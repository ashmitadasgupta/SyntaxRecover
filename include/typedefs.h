#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "token_stream.h"

/* C cannot be parsed without knowing which identifiers are typedef names
 * ("size_t x;" is a declaration, "a * b;" is an expression).
 *
 * Fill eff[0..ts->count-1] with the token type the PARSER should see for each token:
 * the same as the token's own type, except that an identifier that names a typedef
 * becomes T_TYPEDEF_NAME. `eff` must have room for ts->count ints.
 * Returns 0, or -1 if memory ran out. */
int classify_typedef_names(const TokenStream *ts, int *eff);

#endif
