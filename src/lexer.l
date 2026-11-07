%option noyywrap nounput noinput never-interactive prefix="lx"

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "token_stream.h"
#include "lexer.h"
#include "parser.tab.h"

/* ---- state for the current lex_source() call ---- */
static TokenStream *g_out;      /* where tokens are stored              */
static int    g_line, g_col;    /* position of the NEXT character        */
static size_t g_off;
static int    t_line, t_col;    /* position where the current token began */
static size_t t_off;
static int    g_errors;         /* number of lexical errors              */
static int    g_oom;            /* set to 1 if malloc/realloc failed     */

static void advance(const char *s, int n);
static void emit(int type, const char *name, const char *note);

/* Runs before EVERY rule action, including whitespace and comments,
 * so the position is always correct. */
#define YY_USER_ACTION \
    t_line = g_line; t_col = g_col; t_off = g_off; advance(yytext, yyleng);

/* EMIT(T_INT) stores type T_INT with the printable name "T_INT". */
#define EMIT(tok)  emit((tok), #tok, NULL)
%}

%%

[ \t\r\f\v]+                    { /* whitespace: skipped */ }
\n                              { /* newline: skipped */ }

"//".*                          { /* line comment: skipped */ }
"/*"([^*]|\*+[^*/])*\*+"/"      { /* block comment: skipped */ }
"/*"([^*]|\*+[^*/])*\**         { emit(T_LEXERR, "T_LEXERR", "unterminated /* comment"); }

^[ \t]*"#".*                    { EMIT(T_PREPROC); }

"int"                           { EMIT(T_INT); }
"char"                          { EMIT(T_CHAR); }
"short"                         { EMIT(T_SHORT); }
"long"                          { EMIT(T_LONG); }
"float"                         { EMIT(T_FLOAT); }
"double"                        { EMIT(T_DOUBLE); }
"void"                          { EMIT(T_VOID); }
"signed"                        { EMIT(T_SIGNED); }
"unsigned"                      { EMIT(T_UNSIGNED); }
"if"                            { EMIT(T_IF); }
"else"                          { EMIT(T_ELSE); }
"while"                         { EMIT(T_WHILE); }
"for"                           { EMIT(T_FOR); }
"do"                            { EMIT(T_DO); }
"switch"                        { EMIT(T_SWITCH); }
"case"                          { EMIT(T_CASE); }
"default"                       { EMIT(T_DEFAULT); }
"break"                         { EMIT(T_BREAK); }
"continue"                      { EMIT(T_CONTINUE); }
"return"                        { EMIT(T_RETURN); }
"goto"                          { EMIT(T_GOTO); }
"struct"                        { EMIT(T_STRUCT); }
"union"                         { EMIT(T_UNION); }
"enum"                          { EMIT(T_ENUM); }
"typedef"                       { EMIT(T_TYPEDEF); }
"sizeof"                        { EMIT(T_SIZEOF); }
"const"                         { EMIT(T_CONST); }
"volatile"                      { EMIT(T_VOLATILE); }
"static"                        { EMIT(T_STATIC); }
"extern"                        { EMIT(T_EXTERN); }
"register"                      { EMIT(T_REGISTER); }
"auto"                          { EMIT(T_AUTO); }
"size_t"                        { EMIT(T_IDENTIFIER); /* or T_TYPEDEF_NAME if you have it */ }
"ssize_t"                       { EMIT(T_IDENTIFIER); }
"FILE"                          { EMIT(T_IDENTIFIER); }

[A-Za-z_][A-Za-z0-9_]*          { EMIT(T_IDENTIFIER); }

0[xX][0-9a-fA-F]+[uUlL]*        { EMIT(T_INT_LIT); }
[0-9]+[uUlL]*                   { EMIT(T_INT_LIT); }
[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?[fFlL]?   { EMIT(T_FLOAT_LIT); }
\.[0-9]+([eE][+-]?[0-9]+)?[fFlL]?         { EMIT(T_FLOAT_LIT); }
[0-9]+[eE][+-]?[0-9]+[fFlL]?              { EMIT(T_FLOAT_LIT); }

\"([^\"\\\n]|\\.)*\"            { EMIT(T_STRING_LIT); }
\"([^\"\\\n]|\\.)*              { emit(T_LEXERR, "T_LEXERR", "unterminated string literal"); }
'([^'\\\n]|\\.)+'               { EMIT(T_CHAR_LIT); }
''                              { emit(T_LEXERR, "T_LEXERR", "empty character constant"); }
'([^'\\\n]|\\.)*                { emit(T_LEXERR, "T_LEXERR", "unterminated character constant"); }

"..."                           { EMIT(T_ELLIPSIS); }
"<<="                           { EMIT(T_SHL_ASSIGN); }
">>="                           { EMIT(T_SHR_ASSIGN); }
"->"                            { EMIT(T_ARROW); }
"++"                            { EMIT(T_INC); }
"--"                            { EMIT(T_DEC); }
"<<"                            { EMIT(T_SHL); }
">>"                            { EMIT(T_SHR); }
"<="                            { EMIT(T_LE); }
">="                            { EMIT(T_GE); }
"=="                            { EMIT(T_EQ); }
"!="                            { EMIT(T_NE); }
"&&"                            { EMIT(T_ANDAND); }
"||"                            { EMIT(T_OROR); }
"*="                            { EMIT(T_MUL_ASSIGN); }
"/="                            { EMIT(T_DIV_ASSIGN); }
"%="                            { EMIT(T_MOD_ASSIGN); }
"+="                            { EMIT(T_ADD_ASSIGN); }
"-="                            { EMIT(T_SUB_ASSIGN); }
"&="                            { EMIT(T_AND_ASSIGN); }
"^="                            { EMIT(T_XOR_ASSIGN); }
"|="                            { EMIT(T_OR_ASSIGN); }

[;,:(){}\[\].&!~\-+*/%<>^|?=]   { emit(yytext[0], NULL, NULL); }

.                               { emit(T_LEXERR, "T_LEXERR", "illegal character"); }

%%

/* Move the "next character" position forward over the text just matched. */
static void advance(const char *s, int n)
{
    int i;
    for (i = 0; i < n; i++) {
        g_off++;
        if (s[i] == '\n') {
            g_line++;
            g_col = 1;
        } else {
            g_col++;
        }
    }
}

/* Store the token that was just matched. */
static void emit(int type, const char *name, const char *note)
{
    Token t;
    char *copy = malloc((size_t)yyleng + 1);
    if (copy == NULL) {
        g_oom = 1;
        return;
    }
    memcpy(copy, yytext, (size_t)yyleng);
    copy[yyleng] = '\0';

    t.type   = type;
    t.name   = name;
    t.text   = copy;
    t.line   = t_line;
    t.col    = t_col;
    t.offset = t_off;
    t.length = (size_t)yyleng;
    t.note   = note;

    if (ts_push(g_out, t) != 0) {
        free(copy);
        g_oom = 1;
        return;
    }
    if (note != NULL) {
        g_errors++;
    }
}

int lex_source(const char *src, TokenStream *out)
{
    YY_BUFFER_STATE buf;

    g_out = out;
    g_line = 1;
    g_col = 1;
    g_off = 0;
    g_errors = 0;
    g_oom = 0;

    buf = yy_scan_string(src);
    yylex();                      /* no rule returns, so this scans to the end */
    yy_delete_buffer(buf);

    if (!g_oom) {                 /* append the end-of-input token */
        Token t;
        char *empty = malloc(1);
        if (empty == NULL) {
            g_oom = 1;
        } else {
            empty[0] = '\0';
            t.type = 0;
            t.name = "EOF";
            t.text = empty;
            t.line = g_line;
            t.col = g_col;
            t.offset = g_off;
            t.length = 0;
            t.note = NULL;
            if (ts_push(out, t) != 0) {
                free(empty);
                g_oom = 1;
            }
        }
    }
    return g_oom ? -1 : g_errors;
}