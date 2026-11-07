#ifndef REPORTER_H
#define REPORTER_H

#include "edits.h"

/* Print one numbered, explained entry for every edit: error category, line:column,
 * the source line with a caret, what is wrong, and the suggested fix.
 * `src` is the ORIGINAL source text the edits refer to. */
void report_fixes(const char *src, const EditList *edits);

#endif