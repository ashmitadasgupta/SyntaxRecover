#ifndef EDITS_H
#define EDITS_H

#include <stddef.h>

/* What one repair does to the token stream. */
typedef enum {
    EDIT_INSERT,    /* insert a token just before the bad token */
    EDIT_DELETE,    /* remove the bad token                      */
    EDIT_REPLACE    /* replace the bad token with another one    */
} EditKind;

/* One repair step, described in terms of the ORIGINAL source. */
typedef struct {
    EditKind kind;
    int      line, col;       /* position of the bad token in the original source        */
    size_t   offset;          /* byte offset of the bad token in the original source      */
    size_t   at;              /* insert only: where to put the text (end of the previous token) */
    int      before_eof;      /* 1 if the bad token was the end of the file               */
    size_t   length;          /* bytes of original text removed (0 for a pure insert)     */
    char     found[64];       /* text of the bad token ("end of file" at the end)         */
    char     inserted[64];    /* text inserted (empty for a delete)                       */
} Edit;

/* A growable list of edits, in the order they were found. */
typedef struct {
    Edit  *items;
    size_t count;
    size_t capacity;
} EditList;

void        edits_init(EditList *l);
void        edits_free(EditList *l);
int         edits_push(EditList *l, Edit e);      /* returns 0, or -1 if out of memory */
const char *edit_kind_name(EditKind k);

/* Apply all edits to the ORIGINAL source text and return the corrected text
 * (malloc'ed; the caller frees it). Returns NULL if out of memory. */
char       *edits_apply(const char *src, const EditList *l);

#endif