#ifndef VALIDATOR_H
#define VALIDATOR_H

/* Lex and parse `src` from scratch.
 * Returns 1 if it has no lexical and no syntax errors, 0 if errors remain,
 * -1 if memory ran out. */
int validate_source(const char *src);

#endif