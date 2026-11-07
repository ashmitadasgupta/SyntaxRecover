#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include <stddef.h>
#include "common.h"

/* A growable array of tokens. */
typedef struct {
    Token  *items;
    size_t  count;
    size_t  capacity;
} TokenStream;

void ts_init(TokenStream *ts);          /* make an empty stream            */
void ts_free(TokenStream *ts);          /* free all tokens and the array   */
int  ts_push(TokenStream *ts, Token t); /* append; returns 0, or -1 on out-of-memory */

#endif