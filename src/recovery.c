#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "common.h"
#include "token_stream.h"
#include "parse.h"
#include "edits.h"
#include "recovery.h"
#include "parser.tab.h"          /* T_* token codes */

#define MAX_EDITS 100            /* safety limit: stop after this many repairs */

/* ------------------------------------------------------------------------
 * Table of every token the parser can ask for.
 * Bison reports expected tokens by NAME ("';'" or "T_ARROW"). This table
 * turns a name into (token code, text to write into the source).
 * rank = tie-breaker: when two repairs work equally well, smaller wins.
 * ------------------------------------------------------------------------ */
typedef struct {
    const char *sym;     /* name exactly as Bison prints it                 */
    int         type;    /* token code the parser understands               */
    const char *name;    /* printable token name, NULL for 1-char tokens    */
    const char *text;    /* source text to insert                           */
    int         rank;
} SymInfo;

#define TK(t, txt, r)  { #t, t, #t, txt, r }

static const SymInfo symtab[] = {
    /* punctuation that is most often forgotten */
    { "';'", ';', NULL, ";", 0 },
    { "')'", ')', NULL, ")", 1 },
    { "'}'", '}', NULL, "}", 2 },
    { "']'", ']', NULL, "]", 3 },
    { "','", ',', NULL, ",", 4 },
    { "':'", ':', NULL, ":", 5 },
    /* openers: rarely the right guess, so they rank last */
    { "'('", '(', NULL, "(", 9 },
    { "'{'", '{', NULL, "{", 9 },
    { "'['", '[', NULL, "[", 9 },
    /* one-character operators */
    { "'='", '=', NULL, "=", 6 },
    { "'?'", '?', NULL, "?", 6 },
    { "'.'", '.', NULL, ".", 6 },
    { "'&'", '&', NULL, "&", 6 },
    { "'!'", '!', NULL, "!", 6 },
    { "'~'", '~', NULL, "~", 6 },
    { "'-'", '-', NULL, "-", 6 },
    { "'+'", '+', NULL, "+", 6 },
    { "'*'", '*', NULL, "*", 6 },
    { "'/'", '/', NULL, "/", 6 },
    { "'%'", '%', NULL, "%", 6 },
    { "'<'", '<', NULL, "<", 6 },
    { "'>'", '>', NULL, ">", 6 },
    { "'^'", '^', NULL, "^", 6 },
    { "'|'", '|', NULL, "|", 6 },
    /* multi-character operators */
    TK(T_ELLIPSIS,   "...", 6), TK(T_ARROW,      "->",  6),
    TK(T_INC,        "++",  6), TK(T_DEC,        "--",  6),
    TK(T_SHL,        "<<",  6), TK(T_SHR,        ">>",  6),
    TK(T_LE,         "<=",  6), TK(T_GE,         ">=",  6),
    TK(T_EQ,         "==",  6), TK(T_NE,         "!=",  6),
    TK(T_ANDAND,     "&&",  6), TK(T_OROR,       "||",  6),
    TK(T_MUL_ASSIGN, "*=",  6), TK(T_DIV_ASSIGN, "/=",  6),
    TK(T_MOD_ASSIGN, "%=",  6), TK(T_ADD_ASSIGN, "+=",  6),
    TK(T_SUB_ASSIGN, "-=",  6), TK(T_SHL_ASSIGN, "<<=", 6),
    TK(T_SHR_ASSIGN, ">>=", 6), TK(T_AND_ASSIGN, "&=",  6),
    TK(T_XOR_ASSIGN, "^=",  6), TK(T_OR_ASSIGN,  "|=",  6),
    /* names and literals: we can only insert a placeholder */
    TK(T_IDENTIFIER, "missing_name", 7), TK(T_INT_LIT,    "0",    7),
    TK(T_FLOAT_LIT,  "0.0",          7), TK(T_CHAR_LIT,   "'a'",  7),
    TK(T_STRING_LIT, "\"\"",         7),
    /* keywords */
    TK(T_INT,   "int",   8), TK(T_CHAR,  "char",  8), TK(T_SHORT,  "short",  8),
    TK(T_LONG,  "long",  8), TK(T_FLOAT, "float", 8), TK(T_DOUBLE, "double", 8),
    TK(T_VOID,  "void",  8), TK(T_SIGNED, "signed", 8), TK(T_UNSIGNED, "unsigned", 8),
    TK(T_IF,    "if",    8), TK(T_ELSE,  "else",  8), TK(T_WHILE,  "while",  8),
    TK(T_FOR,   "for",   8), TK(T_DO,    "do",    8), TK(T_SWITCH, "switch", 8),
    TK(T_CASE,  "case",  8), TK(T_DEFAULT, "default", 8),
    TK(T_BREAK, "break", 8), TK(T_CONTINUE, "continue", 8),
    TK(T_RETURN, "return", 8), TK(T_GOTO, "goto", 8),
    TK(T_STRUCT, "struct", 8), TK(T_UNION, "union", 8), TK(T_ENUM, "enum", 8),
    TK(T_TYPEDEF, "typedef", 8), TK(T_SIZEOF, "sizeof", 8),
    TK(T_CONST, "const", 8), TK(T_VOLATILE, "volatile", 8),
    TK(T_STATIC, "static", 8), TK(T_EXTERN, "extern", 8),
    TK(T_REGISTER, "register", 8), TK(T_AUTO, "auto", 8)
};

static const SymInfo *find_sym(const char *name)
{
    size_t i;
    for (i = 0; i < sizeof symtab / sizeof symtab[0]; i++) {
        if (strcmp(symtab[i].sym, name) == 0) {
            return &symtab[i];
        }
    }
    return NULL;
}

/* A closer (or ';') may be inserted even if it does not let the parser reach a new
 * original token: it still closes something that was left open. */
static int is_closer(const SymInfo *s)
{
    return s != NULL && (s->type == ';' || s->type == ')' || s->type == ']' || s->type == '}');
}

/* ------------------------------------------------------------------------
 * One candidate repair and how well it did.
 * ------------------------------------------------------------------------ */
typedef struct {
    EditKind       kind;
    const SymInfo *sym;     /* token inserted/used as replacement; NULL for delete */
    long           score;   /* how far the parser got, in ORIGINAL token numbers   */
    int            cost;    /* 1 = cheap insert, 2 = delete, 3 = anything else    */
    int            rank;    /* tie-breaker from the symbol table                   */
} Cand;

/* Make `t` a token for symbol `s`, located where `at` is. */
/* Where a token inserted before work[i] goes in the source text:
 * right after the previous token (so a missing ';' lands next to its statement). */
static size_t insert_point(const Token *work, size_t i)
{
    if (i == 0) {
        return work[0].offset;
    }
    return work[i - 1].offset + work[i - 1].length;
}

/* Make `t` a token for symbol `s`. `at` supplies line/column; `off` is stored as the
 * token's offset (for an inserted token that is the insertion point, with length 0). */
static void fill_token(Token *t, const SymInfo *s, const Token *at, int keep_length, size_t off)
{
    t->type   = s->type;
    t->name   = s->name;
    t->text   = (char *)s->text;   /* never freed or modified: recovery owns no token text */
    t->line   = at->line;
    t->col    = at->col;
    t->offset = off;
    t->length = keep_length ? at->length : 0;
    t->note   = NULL;
}

/* Copy `work` into `out`, apply one edit at position i, return the new token count. */
static size_t apply_edit(Token *out, const Token *work, size_t wn, size_t i,
                         EditKind kind, const SymInfo *s)
{
    memcpy(out, work, wn * sizeof *work);
    if (kind == EDIT_INSERT) {
        memmove(out + i + 1, out + i, (wn - i) * sizeof *out);
        fill_token(&out[i], s, &work[i], 0, insert_point(work, i));
        return wn + 1;
    }
    if (kind == EDIT_DELETE) {
        memmove(out + i, out + i + 1, (wn - i - 1) * sizeof *out);
        return wn - 1;
    }
    fill_token(&out[i], s, &work[i], 1, work[i].offset);          /* replace */
    return wn;
}
/* Try one edit. Returns 1 and fills *c if the edit is a real improvement, else 0. */
static int try_edit(const Token *work, size_t wn, size_t i, EditKind kind,
                    const SymInfo *s, Token *scratch, Cand *c)
{
    TokenStream view;
    ParseResult r;
    size_t cn, e;
    int rc;

    cn = apply_edit(scratch, work, wn, i, kind, s);
    view.items = scratch;
    view.count = cn;
    view.capacity = cn;
    rc = parse_tokens(&view, &r);

    c->kind = kind;
    c->sym  = s;
    c->rank = s ? s->rank : 5;
    /* cheapest: insert punctuation/operator; then delete; then anything that invents a
     * name, a literal or a keyword (rank >= 7) or replaces a token */
    if (kind == EDIT_INSERT)      c->cost = (s->rank >= 7) ? 3 : 1;
    else if (kind == EDIT_DELETE) c->cost = 2;
    else                          c->cost = 3;

    if (rc == 0) {                       /* the whole file parses now */
        c->score = LONG_MAX;
        return 1;
    }
    if (rc != 1 || !r.found) {
        return 0;
    }
    e = r.token_index;                   /* where the NEW first error is */

    if (kind == EDIT_INSERT) {
        if (e <= i) return 0;            /* parser still rejects the inserted token */
        c->score = (long)e - 1;          /* the inserted token takes one slot */
        if (c->score == (long)i && !is_closer(s)) return 0;   /* no original token consumed */
        return 1;
    }
    if (kind == EDIT_REPLACE) {
        if (e <= i) return 0;
        c->score = (long)e;
        return 1;
    }
    /* delete: the token that used to be at i+1 is now at i */
    c->score = (long)e + 1;
    return 1;
}

static int better(const Cand *a, const Cand *b)
{
    if (a->score != b->score) return a->score > b->score;
    if (a->cost  != b->cost)  return a->cost  < b->cost;
    return a->rank < b->rank;
}

/* Try every candidate repair for the error at token i; put the best in *best. */
static int choose_repair(const Token *work, size_t wn, size_t i, const ParseResult *res,
                         Token *scratch, Cand *best)
{
    int have = 0, k;
    int at_eof = (work[i].type == 0);
    Cand c;

    for (k = 0; k < res->expected_count; k++) {
        const SymInfo *s = find_sym(res->expected[k]);
        if (s == NULL) continue;

        if (try_edit(work, wn, i, EDIT_INSERT, s, scratch, &c) && (!have || better(&c, best))) {
            *best = c;
            have = 1;
        }
        if (!at_eof &&
            try_edit(work, wn, i, EDIT_REPLACE, s, scratch, &c) && (!have || better(&c, best))) {
            *best = c;
            have = 1;
        }
    }
    if (!at_eof &&
        try_edit(work, wn, i, EDIT_DELETE, NULL, scratch, &c) && (!have || better(&c, best))) {
        *best = c;
        have = 1;
    }
    return have;
}

static int record_edit(EditList *edits, const Token *work, size_t i, const Cand *c)
{
    const Token *bad = &work[i];
    Edit e;
    memset(&e, 0, sizeof e);
    e.kind       = c->kind;
    e.line       = bad->line;
    e.col        = bad->col;
    e.offset     = bad->offset;
    e.length     = (c->kind == EDIT_INSERT) ? 0 : bad->length;
    e.at         = (c->kind == EDIT_INSERT) ? insert_point(work, i) : bad->offset;
    e.before_eof = (bad->type == 0);
    if (bad->type == 0) {
        snprintf(e.found, sizeof e.found, "%s", "end of file");
    } else {
        snprintf(e.found, sizeof e.found, "%s", bad->text);
    }
    if (c->sym != NULL) {
        snprintf(e.inserted, sizeof e.inserted, "%s", c->sym->text);
    }
    return edits_push(edits, e);
}

int recover_syntax(const TokenStream *ts, EditList *edits)
{
    size_t cap = ts->count + MAX_EDITS + 2;
    Token *work;
    Token *scratch;
    size_t wn = ts->count;
    int round, result = RECOVER_PARTIAL;
    size_t j;

    work = malloc(cap * sizeof *work);
    scratch = malloc(cap * sizeof *scratch);
    
    if (work == NULL || scratch == NULL) {
        free(work);
        free(scratch);
        return RECOVER_NOMEM;
    }
    memcpy(work, ts->items, wn * sizeof *work);

    /* ---- NEW: Lexical Repair Pass (Now updates the work array!) ---- */
    /* We loop backwards so deletions do not shift our current index */
    for (j = wn; j > 0; j--) {
        size_t i = j - 1;
        Token *t = &work[i];
        
        if (t->type == T_LEXERR && t->note != NULL) {
            Edit e;
            memset(&e, 0, sizeof e);
            e.line = t->line;
            e.col = t->col;
            e.before_eof = 0;
            snprintf(e.found, sizeof e.found, "%s", t->text);

            if (strcmp(t->note, "illegal character") == 0) {
                e.kind = EDIT_DELETE;
                e.offset = t->offset;
                e.length = t->length;
                e.at = t->offset;
                if (edits_push(edits, e) != 0) return RECOVER_NOMEM;
                
                /* Sync parser: Delete illegal characters from the token stream */
                wn = apply_edit(scratch, work, wn, i, EDIT_DELETE, NULL);
                memcpy(work, scratch, wn * sizeof *work);
                
            } else if (strcmp(t->note, "unterminated string literal") == 0) {
                e.kind = EDIT_INSERT;
                e.offset = t->offset;
                e.length = 0;
                e.at = t->offset + t->length;
                snprintf(e.inserted, sizeof e.inserted, "\"");
                if (edits_push(edits, e) != 0) return RECOVER_NOMEM;
                
                /* Sync parser: Convert LEXERR into a valid string token */
                t->type = T_STRING_LIT;
                t->name = "T_STRING_LIT";
                
            } else if (strcmp(t->note, "unterminated /* comment") == 0) {
                e.kind = EDIT_INSERT;
                e.offset = t->offset;
                e.length = 0;
                e.at = t->offset + t->length;
                snprintf(e.inserted, sizeof e.inserted, "*/");
                if (edits_push(edits, e) != 0) return RECOVER_NOMEM;
                
                /* Sync parser: Comments are ignored, so delete it from the stream */
                wn = apply_edit(scratch, work, wn, i, EDIT_DELETE, NULL);
                memcpy(work, scratch, wn * sizeof *work);
            }
        }
    }
    /* ---------------------------------- */

    for (round = 0; round <= MAX_EDITS; round++) {
        // ... the rest of the function remains exactly the same ...
        TokenStream view;
        ParseResult res;
        Cand best;
        size_t i, new_n;
        int rc;

        view.items = work;
        view.count = wn;
        view.capacity = wn;
        rc = parse_tokens(&view, &res);

        if (rc == 0) {
            result = RECOVER_OK;
            break;
        }
        if (rc != 1 || !res.found || round == MAX_EDITS) {
            break;                                   /* give up */
        }
        i = res.token_index;
        if (!choose_repair(work, wn, i, &res, scratch, &best)) {
            break;                                   /* nothing helps */
        }
        if (record_edit(edits, work, i, &best) != 0) {
            result = RECOVER_NOMEM;
            break;
        }
        new_n = apply_edit(scratch, work, wn, i, best.kind, best.sym);
        memcpy(work, scratch, new_n * sizeof *work);
        wn = new_n;
    }

    free(work);
    free(scratch);
    return result;
}
