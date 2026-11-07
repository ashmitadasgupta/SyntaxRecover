#include <stdio.h>
#include <string.h>
#include "edits.h"
#include "reporter.h"

/* ------------------------------------------------------------------------
 * Locating a byte offset in the source
 * ------------------------------------------------------------------------ */
typedef struct {
    int    line, col;      /* 1-based; a tab counts as one column (same as the lexer) */
    size_t start, end;     /* byte range of that line, without the newline            */
} Loc;
static Loc locate(const char *src, size_t pos)
{
    Loc loc;
    size_t n = strlen(src), i;

    if (pos > n) {
        pos = n;
    }
    loc.line = 1;
    loc.start = 0;
    for (i = 0; i < pos; i++) {
        if (src[i] == '\n') {
            loc.line++;
            loc.start = i + 1;
        }
    }
    loc.col = (int)(pos - loc.start) + 1;
    loc.end = loc.start;
    while (src[loc.end] != '\0' && src[loc.end] != '\n') {
        loc.end++;
    }
    return loc;
}

/* Print the line with its number, and a row of ^ under the offending place. */
static void show_line(const char *src, const Loc *loc, size_t carets)
{
    size_t i, len = loc->end - loc->start;

    if (len > 0 && src[loc->end - 1] == '\r') {
        len--;                                    /* hide a Windows line ending */
    }
    printf("  %4d | %.*s\n", loc->line, (int)len, src + loc->start);
    printf("       | ");
    for (i = 0; i + 1 < (size_t)loc->col; i++) {
        char c = (loc->start + i < loc->end) ? src[loc->start + i] : ' ';
        putchar(c == '\t' ? '\t' : ' ');          /* keep tabs so the caret lines up */
    }
    for (i = 0; i < carets; i++) {
        putchar('^');
    }
    putchar('\n');
}

/* ------------------------------------------------------------------------
 * Classifying an edit
 * ------------------------------------------------------------------------ */
static int in_list(const char *t, const char *const *list)
{
    size_t i;
    for (i = 0; list[i] != NULL; i++) {
        if (strcmp(t, list[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Name the kind of operator `t` is, or NULL if it is not an operator. */
static const char *operator_class(const char *t)
{
    static const char *const arith[]  = { "+", "-", "*", "/", "%", "++", "--", NULL };
    static const char *const rel[]    = { "<", ">", "<=", ">=", "==", "!=", NULL };
    static const char *const logic[]  = { "&&", "||", "!", NULL };
    static const char *const bits[]   = { "&", "|", "^", "~", "<<", ">>", NULL };
    static const char *const assign[] = { "=", "+=", "-=", "*=", "/=", "%=", "<<=", ">>=",
                                          "&=", "^=", "|=", NULL };
    static const char *const member[] = { ".", "->", NULL };

    if (in_list(t, arith))  return "arithmetic operator";
    if (in_list(t, rel))    return "relational operator";
    if (in_list(t, logic))  return "logical operator";
    if (in_list(t, bits))   return "bitwise operator";
    if (in_list(t, assign)) return "assignment operator";
    if (in_list(t, member)) return "member-access operator";
    if (strcmp(t, "?") == 0) return "conditional operator";
    return NULL;
}

static int is_delimiter(const char *t)
{
    static const char *const d[] = { ";", ",", ":", "(", ")", "[", "]", "{", "}", NULL };
    return in_list(t, d);
}

/* The text of a placeholder we invent when a name or value is missing. */
static int is_placeholder_name(const char *t)  { return strcmp(t, "missing_name") == 0; }
static int is_placeholder_value(const char *t)
{
    return strcmp(t, "0") == 0 || strcmp(t, "0.0") == 0 ||
           strcmp(t, "'a'") == 0 || strcmp(t, "\"\"") == 0;
}

typedef struct {
    const char *category;
    char        problem[200];
} Info;

static void classify_insert(const Edit *e, Info *info)
{
    const char *t = e->inserted;
    const char *op;

    if (strcmp(t, ";") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing ';' - the statement or declaration is not terminated.");
    } else if (strcmp(t, ")") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing ')' - a parenthesis was opened but never closed.");
    } else if (strcmp(t, "]") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing ']' - a square bracket was opened but never closed.");
    } else if (strcmp(t, "}") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem, "%s",
                 e->before_eof ? "Missing '}' - the end of the file was reached while a block was still open."
                               : "Missing '}' - a block was opened with '{' but never closed.");
    } else if (strcmp(t, ",") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing ',' - items in a list must be separated by commas.");
    } else if (strcmp(t, ":") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing ':' - expected after a case/default label or in a '?:' expression.");
    } else if (strcmp(t, "(") == 0 || strcmp(t, "[") == 0 || strcmp(t, "{") == 0) {
        info->category = "Missing delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Missing opening '%s' - something here must be enclosed in brackets.", t);
    } else if ((op = operator_class(t)) != NULL) {
        info->category = "Missing operator";
        snprintf(info->problem, sizeof info->problem,
                 "%s %s ('%s') is missing here.",
                 strchr("aeiou", op[0]) ? "An" : "A", op, t);
    } else if (is_placeholder_name(t)) {
        info->category = "Missing identifier";
        snprintf(info->problem, sizeof info->problem,
                 "A name (identifier) is missing here, for example a variable or function name.");
    } else if (is_placeholder_value(t)) {
        info->category = "Missing operand";
        snprintf(info->problem, sizeof info->problem,
                 "An operand (a value or expression) is missing here.");
    } else {
        info->category = "Missing keyword";
        snprintf(info->problem, sizeof info->problem,
                 "The keyword '%s' is missing here.", t);
    }
}

static void classify_delete(const Edit *e, Info *info)
{
    const char *t = e->found;
    const char *op;

    if (strcmp(t, ")") == 0 || strcmp(t, "]") == 0 || strcmp(t, "}") == 0) {
        info->category = "Extra delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Unexpected '%s' - there is no matching opening bracket for it.", t);
    } else if (is_delimiter(t)) {
        info->category = "Extra delimiter";
        snprintf(info->problem, sizeof info->problem,
                 "Unexpected '%s' - it is not allowed at this position.", t);
    } else if ((op = operator_class(t)) != NULL) {
        info->category = "Misplaced operator";
        snprintf(info->problem, sizeof info->problem,
                 "Unexpected %s '%s' - it is duplicated or in the wrong place.", op, t);
    } else {
        info->category = "Unexpected token";
        snprintf(info->problem, sizeof info->problem,
                 "Unexpected '%s' - it cannot appear here.", t);
    }
}

static void classify_replace(const Edit *e, Info *info)
{
    if (operator_class(e->found) != NULL && operator_class(e->inserted) != NULL) {
        info->category = "Incorrect operator";
    } else if (is_delimiter(e->found) && is_delimiter(e->inserted)) {
        info->category = "Incorrect delimiter";
    } else {
        info->category = "Incorrect token";
    }
    snprintf(info->problem, sizeof info->problem,
             "'%s' is not valid here; '%s' fits the surrounding code.", e->found, e->inserted);
}

/* ------------------------------------------------------------------------
 * The report
 * ------------------------------------------------------------------------ */
void report_fixes(const char *src, const EditList *edits)
{
    size_t i, n = strlen(src);

    if (edits->count == 0) {
        return;
    }
    printf("\n===== Syntax error report =====\n");

    for (i = 0; i < edits->count; i++) {
        const Edit *e = &edits->items[i];
        Info info;
        Loc loc;
        size_t pos, carets = 1;

        /* where to point: the place where the fix happens */
        if (e->kind == EDIT_INSERT) {
            pos = e->at;
            if (e->before_eof && strcmp(e->inserted, "}") == 0) {
                pos = (n > 0 && src[n - 1] == '\n') ? n - 1 : n;     /* end of the last line */
            }
        } else {
            pos = e->offset;
            if (e->length > 1) {
                carets = e->length;
            }
        }
        loc = locate(src, pos);

        if (e->kind == EDIT_INSERT)       classify_insert(e, &info);
        else if (e->kind == EDIT_DELETE)  classify_delete(e, &info);
        else                              classify_replace(e, &info);

        printf("\nError %zu [%s] at line %d, column %d\n", i + 1, info.category, loc.line, loc.col);
        show_line(src, &loc, carets);
        printf("  Problem : %s\n", info.problem);
        if (e->kind == EDIT_INSERT) {
            printf("  Fix     : insert '%s' here\n", e->inserted);
            if (e->line != loc.line || e->col != loc.col) {
                if (e->before_eof) {
                    printf("  Detected: the parser only noticed at the end of the file\n");
                } else {
                    printf("  Detected: the parser only noticed at line %d, column %d ('%s')\n",
                           e->line, e->col, e->found);
                }
            }
        } else if (e->kind == EDIT_DELETE) {
            printf("  Fix     : delete '%s'\n", e->found);
        } else {
            printf("  Fix     : replace '%s' with '%s'\n", e->found, e->inserted);
        }
    }
    printf("\n%zu syntax error(s) reported.\n", edits->count);
}