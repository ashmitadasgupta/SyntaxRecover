#ifndef PARSE_H
#define PARSE_H

#include <stddef.h>
#include "token_stream.h"

#define PARSE_MAX_EXPECTED 256

/* Result of one parse attempt. */
typedef struct {
    int         found;                         /* 1 if a syntax error was detected          */
    size_t      token_index;                   /* index in the TokenStream of the bad token */
    int         expected_count;                /* number of entries in expected[]           */
    const char *expected[PARSE_MAX_EXPECTED];  /* names of the tokens that would have been valid */
} ParseResult;

/* Parse the token stream.
 * Returns 0 if accepted, 1 if a syntax error was found (details in *res),
 * 2 if the parser ran out of memory. */
int parse_tokens(const TokenStream *ts, ParseResult *res);

#endif