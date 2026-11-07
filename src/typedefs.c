#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "token_stream.h"
#include "typedefs.h"
#include "parser.tab.h"

#define NONE         ((size_t)-1)
#define MAX_DECLS    64          /* names declared by ONE typedef statement */

/* Names that normally come from system headers. We do not read headers, so we
 * simply know them in advance. */
static const char *const builtin_names[] = {
    "size_t", "ssize_t", "ptrdiff_t", "wchar_t", "FILE", "va_list", "time_t", "clock_t",
    "off_t", "bool", "int8_t", "int16_t", "int32_t", "int64_t", "uint8_t", "uint16_t",
    "uint32_t", "uint64_t", "intptr_t", "uintptr_t", "intmax_t", "uintmax_t",
    "sig_atomic_t", "div_t", "ldiv_t", "fpos_t", NULL
};

/* ---- a growable set of names (pointers into the token texts) ---- */
typedef struct {
    const char **items;
    size_t       count, cap;
} NameSet;

static int set_add(NameSet *s, const char *name)
{
    if (s->count == s->cap) {
        size_t nc = s->cap ? s->cap * 2 : 16;
        const char **p = realloc(s->items, nc * sizeof *p);
        if (p == NULL) {
            return -1;
        }
        s->items = p;
        s->cap = nc;
    }
    s->items[s->count++] = name;
    return 0;
}

static int set_has(const NameSet *s, const char *name)
{
    size_t i;
    for (i = 0; builtin_names[i] != NULL; i++) {
        if (strcmp(builtin_names[i], name) == 0) {
            return 1;
        }
    }
    for (i = 0; i < s->count; i++) {
        if (strcmp(s->items[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Tokens the parser never sees. */
static int skippable(int type)
{
    return type == T_PREPROC || type == T_LEXERR;
}

/* Index of the next token the parser can see, starting at i (or n if none). */
static size_t next_sig(const TokenStream *ts, size_t i)
{
    while (i < ts->count && skippable(ts->items[i].type)) {
        i++;
    }
    return i;
}

/* ts->items[start] is a 'typedef' keyword. Find the identifiers this statement
 * declares (stored in names[]) and the index of the ';' that ends it.
 *
 *   typedef unsigned long ulong;            -> ulong
 *   typedef struct node {...} Node, *NodeP; -> Node, NodeP
 *   typedef int (*handler)(int);            -> handler
 *   typedef char name_t[32];                -> name_t
 *
 * Rule: split at commas that are not inside (), [] or {}; in each piece the name is
 * the identifier inside "( * name )" if there is one, else the last identifier that
 * is not nested inside brackets. */
static void find_typedef_names(const TokenStream *ts, size_t start,
                               size_t *names, int *nnames, size_t *end)
{
    size_t n = ts->count, i;
    size_t last_ident = NONE, fp_name = NONE;
    int depth = 0;

    *nnames = 0;
    for (i = start + 1; i < n; i++) {
        int t = ts->items[i].type;

        if (skippable(t)) {
            continue;
        }
        if (t == 0) {
            break;                                  /* end of file */
        }
        if (t == '(' && depth == 0 && fp_name == NONE) {
            size_t j = next_sig(ts, i + 1);
            if (j < n && ts->items[j].type == '*') {
                while (j < n && (ts->items[j].type == '*' || ts->items[j].type == T_CONST ||
                                 ts->items[j].type == T_VOLATILE || skippable(ts->items[j].type))) {
                    j++;
                }
                if (j < n && ts->items[j].type == T_IDENTIFIER) {
                    fp_name = j;
                }
            }
        }
        if (t == '(' || t == '[' || t == '{') {
            depth++;
        } else if (t == ')' || t == ']' || t == '}') {
            if (depth > 0) {
                depth--;
            }
        } else if (depth == 0 && t == T_IDENTIFIER) {
            last_ident = i;
        } else if (depth == 0 && (t == ',' || t == ';')) {
            size_t name = (fp_name != NONE) ? fp_name : last_ident;
            if (name != NONE && *nnames < MAX_DECLS) {
                names[(*nnames)++] = name;
            }
            last_ident = NONE;
            fp_name = NONE;
            if (t == ';') {
                *end = i;
                return;
            }
        }
    }
    *end = n;                                       /* no ';' found: statement runs to the end */
}

int classify_typedef_names(const TokenStream *ts, int *eff)
{
    NameSet known = { NULL, 0, 0 };
    size_t pending[MAX_DECLS];                      /* declarator names of the open typedef */
    int    npending = 0, have_pending = 0, k;
    size_t pending_end = 0, i, n = ts->count;
    int    prev = 0;                                /* previous token the parser sees */

    for (i = 0; i < n; i++) {
        const Token *t = &ts->items[i];
        eff[i] = t->type;
        if (skippable(t->type)) {
            continue;
        }

        /* the typedef statement is over: its names are usable from now on */
        if (have_pending && i > pending_end) {
            for (k = 0; k < npending; k++) {
                if (set_add(&known, ts->items[pending[k]].text) != 0) {
                    free(known.items);
                    return -1;
                }
            }
            have_pending = 0;
        }

        if (t->type == T_IDENTIFIER && set_has(&known, t->text)) {
            int declaring = 0;
            for (k = 0; have_pending && k < npending; k++) {
                if (pending[k] == i) {
                    declaring = 1;                  /* this is the name being declared */
                }
            }
            /* "struct Node", "x.Node" and "p->Node" use Node as a plain name */
            if (!declaring && prev != T_STRUCT && prev != T_UNION && prev != T_ENUM &&
                prev != '.' && prev != T_ARROW) {
                eff[i] = T_TYPEDEF_NAME;
            }
        }
        if (t->type == T_TYPEDEF && !have_pending) {
            find_typedef_names(ts, i, pending, &npending, &pending_end);
            have_pending = 1;
        }
        prev = eff[i];
    }
    free(known.items);
    return 0;
}