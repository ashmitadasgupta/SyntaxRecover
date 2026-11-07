#include "token_stream.h"
#include "lexer.h"
#include "parse.h"
#include "validator.h"

int validate_source(const char *src)
{
    TokenStream ts;
    ParseResult res;
    int lex_errors, rc;

    ts_init(&ts);
    lex_errors = lex_source(src, &ts);
    if (lex_errors < 0) {
        ts_free(&ts);
        return -1;
    }
    rc = parse_tokens(&ts, &res);
    ts_free(&ts);
    if (rc == 2) {
        return -1;
    }
    return (lex_errors == 0 && rc == 0) ? 1 : 0;
}