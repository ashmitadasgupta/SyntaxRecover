#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "token_stream.h"
#include "lexer.h"
#include "parse.h"
#include "edits.h"
#include "recovery.h"
#include "validator.h"
#include "reporter.h"

static const char* get_readable_token_name(const char* token_name) {
    if (!token_name) return "end of file";
    if (strcmp(token_name, "T_INT") == 0) return "keyword 'int'";
    if (strcmp(token_name, "T_RETURN") == 0) return "keyword 'return'";
    if (strcmp(token_name, "T_IF") == 0) return "keyword 'if'";
    if (strcmp(token_name, "T_ELSE") == 0) return "keyword 'else'";
    if (strcmp(token_name, "T_WHILE") == 0) return "keyword 'while'";
    if (strcmp(token_name, "T_FOR") == 0) return "keyword 'for'";
    if (strcmp(token_name, "T_STRUCT") == 0) return "keyword 'struct'";
    if (strcmp(token_name, "T_TYPEDEF") == 0) return "keyword 'typedef'";
    if (strcmp(token_name, "T_IDENTIFIER") == 0) return "identifier";
    if (strcmp(token_name, "T_TYPEDEF_NAME") == 0) return "type name";
    if (strcmp(token_name, "T_CONSTANT") == 0) return "number";
    if (strcmp(token_name, "T_STRING_LITERAL") == 0) return "string";
    if (strcmp(token_name, "T_INC_OP") == 0) return "'++'";
    if (strcmp(token_name, "T_DEC_OP") == 0) return "'--'";
    if (strcmp(token_name, "T_LE_OP") == 0) return "'<='";
    if (strcmp(token_name, "T_GE_OP") == 0) return "'>='";
    if (strcmp(token_name, "T_EQ_OP") == 0) return "'=='";
    if (strcmp(token_name, "T_NE_OP") == 0) return "'!='";
    if (strlen(token_name) == 1 || (token_name[0] == '\'' && token_name[2] == '\'')) {
        return token_name; 
    }
    return token_name;
}

/* Read a whole stream into a NUL-terminated buffer. */
static char *read_all(FILE *fp)
{
    size_t cap = 4096, len = 0, n;
    char *buf = malloc(cap);
    if (buf == NULL) {
        return NULL;
    }
    for (;;) {
        if (cap - len < 2) {
            char *nb = realloc(buf, cap * 2);
            if (nb == NULL) {
                free(buf);
                return NULL;
            }
            buf = nb;
            cap *= 2;
        }
        n = fread(buf + len, 1, cap - len - 1, fp);
        if (n == 0) {
            break;
        }
        len += n;
    }
    buf[len] = '\0';
    return buf;
}

/* Print at most `max` characters of s, showing newline and tab as \n and \t. */
static void print_escaped(const char *s, size_t max)
{
    size_t i;
    for (i = 0; s[i] != '\0'; i++) {
        if (i >= max) {
            fputs("...", stdout);
            return;
        }
        if (s[i] == '\n')      fputs("\\n", stdout);
        else if (s[i] == '\t') fputs("\\t", stdout);
        else                   putchar(s[i]);
    }
}

static void print_tokens(const TokenStream *ts)
{
    size_t i;
    for (i = 0; i < ts->count; i++) {
        const Token *t = &ts->items[i];
        char single[8];
        const char *nm = t->name;
        if (nm == NULL) {
            snprintf(single, sizeof single, "'%c'", t->type);
            nm = single;
        }
        printf("%3d:%-3d  off=%-4zu len=%-2zu %-12s ",
               t->line, t->col, t->offset, t->length, nm);
        print_escaped(t->text, 60);
        putchar('\n');
    }
    printf("Tokens: %zu (including EOF)\n", ts->count);
}

static void report_lexical_errors(const TokenStream *ts)
{
    size_t i;
    for (i = 0; i < ts->count; i++) {
        const Token *t = &ts->items[i];
        if (t->note != NULL) {
            printf("Lexical error at %d:%d (offset %zu): %s: ",
                   t->line, t->col, t->offset, t->note);
            print_escaped(t->text, 30);
            putchar('\n');
        }
    }
}

/* Human-readable description of the token where the parser stopped. */
static void describe_token(const Token *t, char *buf, size_t n)
{
    if (t->type == 0) {
        snprintf(buf, n, "end of file");
    } else if (t->name == NULL) {
        snprintf(buf, n, "'%s'", t->text);
    } else {
        snprintf(buf, n, "%s ('%s')", get_readable_token_name(t->name), t->text);
    }
}

static void report_parse_error(const TokenStream *ts, const ParseResult *res, int verbose)
{
    const Token *t = &ts->items[res->token_index];
    char desc[160];
    int i;

    describe_token(t, desc, sizeof desc);
    printf("Syntax error at %d:%d (offset %zu): unexpected %s\n",
           t->line, t->col, t->offset, desc);
    
    if (!verbose) {
        return;
    }

    if (res->expected_count == 0) {
        printf("  expected: (unknown)\n");
        return;
    }
    printf("  expected (%d possibilities):", res->expected_count);
    for (i = 0; i < res->expected_count; i++) {
        printf(" %s", res->expected[i]);
    }
    putchar('\n');
}

/* Find the repairs, build the corrected program, verify it, optionally save it. */
static void run_recovery(const char *src, const TokenStream *ts, const char *out_path)
{
    EditList edits;
    char *fixed;
    int rr, v;

    edits_init(&edits);
    rr = recover_syntax(ts, &edits);
    if (rr == RECOVER_NOMEM) {
        printf("Recovery: out of memory\n");
        edits_free(&edits);
        return;
    }
    printf("Recovery: %zu fix(es) found; %s\n", edits.count,
           rr == RECOVER_OK ? "the repaired program parses cleanly"
                            : "some errors could not be repaired");
    report_fixes(src, &edits);

    fixed = edits_apply(src, &edits);
    if (fixed == NULL) {
        printf("Could not build the corrected program (out of memory)\n");
        edits_free(&edits);
        return;
    }
    printf("\n----- corrected program -----\n%s", fixed);
    if (fixed[0] != '\0' && fixed[strlen(fixed) - 1] != '\n') {
        putchar('\n');
    }
    printf("----- end of corrected program -----\n");

    v = validate_source(fixed);
    if (v == 1) {
        printf("Verification: the corrected program passes the syntax check.\n");
    } else if (v == 0) {
        printf("Verification: the corrected program STILL has errors.\n");
    } else {
        printf("Verification: out of memory.\n");
    }

    if (out_path != NULL) {
        FILE *fo = fopen(out_path, "wb");
        if (fo == NULL) {
            perror(out_path);
        } else {
            fputs(fixed, fo);
            fclose(fo);
            printf("Corrected program written to %s\n", out_path);
        }
    }
    free(fixed);
    edits_free(&edits);
}

/* ------------------------------------------------------------------------- */
/* NEWLY ADDED STRUCTURAL LOGIC: print_usage and process_file                */
/* ------------------------------------------------------------------------- */

static void print_usage(const char *prog_name) {
    printf("Usage: %s [source_file.c]\n", prog_name);
    printf("If no file is provided, interactive paste-and-run mode will start.\n");
}

static int process_file(FILE *fp, const char *filename, int is_interactive) {
    char *src = read_all(fp);
    if (!src) {
        fprintf(stderr, "Failed to read memory for %s\n", filename);
        return 1;
    }
    rewind(fp);

    /* Point lexer input to the file stream */
    

    TokenStream ts;
    
    /* --------------------------------------------------------------------- */
    /* IMPORTANT: If your project uses different function names to init your */
    /* TokenStream and run your lexer, update the two lines below!           */
    /* --------------------------------------------------------------------- */
    ts_init(&ts);      
    lex_source(src, &ts);    
    /* --------------------------------------------------------------------- */

    report_lexical_errors(&ts);

    ParseResult res;
    int rc = parse_tokens(&ts, &res);

    if (rc == 0) {
        printf("The program parses cleanly!\n");
    } else {
        report_parse_error(&ts, &res, 1);
        run_recovery(src, &ts, is_interactive ? NULL : "repaired_output.c");
    }

    free(src);
    ts_free(&ts);
    return (rc == 0) ? 0 : 1;
}

/* ------------------------------------------------------------------------- */
/* MAIN ENTRY POINT                                                          */
/* ------------------------------------------------------------------------- */

int main(int argc, char **argv) {
    if (argc > 1) {
        /* File Mode */
        if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        }
        
        FILE *fp = fopen(argv[1], "rb");
        if (!fp) {
            perror(argv[1]);
            return 1;
        }
        
        int result = process_file(fp, argv[1], 0);
        fclose(fp);
        return result;
    }

    /* Interactive Mode */
    printf("SyntaxRecover Interactive Mode\n");
    printf("Paste your C code below. Press Ctrl+D (or Ctrl+Z on Windows) on a new line to run.\n");
    printf("--------------------------------------------------------------------------------\n");

    FILE *temp = tmpfile();
    if (!temp) {
        fprintf(stderr, "Error: Could not create temporary file for interactive mode.\n");
        return 1;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        fputs(buffer, temp);
    }

    rewind(temp);
    printf("\n--------------------------------------------------------------------------------\n");
    printf("Analyzing...\n\n");

    int result = process_file(temp, "<stdin>", 1);
    
    fclose(temp);
    return result;
}