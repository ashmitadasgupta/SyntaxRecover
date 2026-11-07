#ifndef LEXER_H
#define LEXER_H

#include "token_stream.h"

/* Split the NUL-terminated string `src` into tokens and append them to `out`.
 * A final token of type 0 (EOF) is always appended.
 * Returns the number of lexical errors found (0 = none), or -1 if memory ran out. */
int lex_source(const char *src, TokenStream *out);

#endif
