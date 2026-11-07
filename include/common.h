#ifndef COMMON_H
#define COMMON_H

#include <stddef.h>

/* One token produced by the lexer. */
typedef struct Token {
    int         type;    /* T_* code from parser.tab.h, or a character such as '+'; 0 = end of input */
    const char *name;    /* printable name such as "T_INT"; NULL for one-character tokens */
    char       *text;    /* exact lexeme (malloc'ed copy, freed by ts_free) */
    int         line;    /* 1-based line of the first character */
    int         col;     /* 1-based column of the first character (a tab counts as 1) */
    size_t      offset;  /* 0-based byte offset of the first character in the source */
    size_t      length;  /* length in bytes */
    const char *note;    /* NULL for a normal token, otherwise a lexical-error message */
} Token;

#endif