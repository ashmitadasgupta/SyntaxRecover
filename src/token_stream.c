#include <stdlib.h>
#include "token_stream.h"

void ts_init(TokenStream *ts)
{
    ts->items = NULL;
    ts->count = 0;
    ts->capacity = 0;
}

void ts_free(TokenStream *ts)
{
    size_t i;
    for (i = 0; i < ts->count; i++) {
        free(ts->items[i].text);
    }
    free(ts->items);
    ts_init(ts);
}

int ts_push(TokenStream *ts, Token tok)
{
    if (ts->count == ts->capacity) {
        size_t new_cap = ts->capacity ? ts->capacity * 2 : 64;
        Token *p = realloc(ts->items, new_cap * sizeof *p);
        if (p == NULL) {
            return -1;
        }
        ts->items = p;
        ts->capacity = new_cap;
    }
    ts->items[ts->count++] = tok;
    return 0;
}