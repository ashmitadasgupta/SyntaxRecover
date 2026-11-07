#ifndef RECOVERY_H
#define RECOVERY_H

#include "token_stream.h"
#include "edits.h"

#define RECOVER_OK      0   /* every error repaired: the repaired token stream parses cleanly */
#define RECOVER_PARTIAL 1   /* gave up: some errors could not be repaired                      */
#define RECOVER_NOMEM   2   /* out of memory                                                   */

/* Repeatedly parse, find the first syntax error, try candidate repairs and keep the best one.
 * The repairs found are appended to `edits`. The input token stream is NOT modified. */
int recover_syntax(const TokenStream *ts, EditList *edits);

#endif