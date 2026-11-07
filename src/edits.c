#include <stdlib.h>
#include <string.h>
#include "edits.h"

void edits_init(EditList *l)
{
    l->items = NULL;
    l->count = 0;
    l->capacity = 0;
}

void edits_free(EditList *l)
{
    free(l->items);
    edits_init(l);
}

int edits_push(EditList *l, Edit e)
{
    if (l->count == l->capacity) {
        size_t new_cap = l->capacity ? l->capacity * 2 : 16;
        Edit *p = realloc(l->items, new_cap * sizeof *p);
        if (p == NULL) {
            return -1;
        }
        l->items = p;
        l->capacity = new_cap;
    }
    l->items[l->count++] = e;
    return 0;
}

const char *edit_kind_name(EditKind k)
{
    switch (k) {
    case EDIT_INSERT:  return "insert";
    case EDIT_DELETE:  return "delete";
    case EDIT_REPLACE: return "replace";
    }
    return "?";
}

/* ------------------------------------------------------------------------
 * Building the corrected source
 * ------------------------------------------------------------------------ */

typedef struct {
    size_t pos;     /* position in the original text where the edit takes effect */
    size_t seq;     /* index in the edit list: keeps edits at the same place in order */
} Slot;

static int cmp_slot(const void *a, const void *b)
{
    const Slot *x = a, *y = b;
    if (x->pos != y->pos) return x->pos < y->pos ? -1 : 1;
    if (x->seq != y->seq) return x->seq < y->seq ? -1 : 1;
    return 0;
}

/* A growable output buffer. */
typedef struct {
    char  *p;
    size_t len, cap;
} Buf;

static int buf_add(Buf *b, const char *s, size_t n)
{
    if (b->len + n + 1 > b->cap) {
        size_t nc = b->cap ? b->cap : 256;
        char *np;
        while (nc < b->len + n + 1) {
            nc *= 2;
        }
        np = realloc(b->p, nc);
        if (np == NULL) {
            return -1;
        }
        b->p = np;
        b->cap = nc;
    }
    memcpy(b->p + b->len, s, n);
    b->len += n;
    b->p[b->len] = '\0';
    return 0;
}

char *edits_apply(const char *src, const EditList *l)
{
    size_t n = strlen(src), i, cursor = 0;
    Slot *slots = NULL;
    Buf out = { NULL, 0, 0 };

    if (l->count > 0) {
        slots = malloc(l->count * sizeof *slots);
        if (slots == NULL) {
            return NULL;
        }
    }
    for (i = 0; i < l->count; i++) {
        const Edit *e = &l->items[i];
        slots[i].seq = i;
        if (e->kind != EDIT_INSERT) {
            slots[i].pos = e->offset;
        } else if (e->before_eof && strcmp(e->inserted, "}") == 0) {
            slots[i].pos = n;                      /* a missing '}' goes at the very end */
        } else {
            slots[i].pos = e->at;
        }
        if (slots[i].pos > n) {
            slots[i].pos = n;
        }
    }
    if (l->count > 0) {
        qsort(slots, l->count, sizeof *slots, cmp_slot);
    }

    for (i = 0; i < l->count; i++) {
        const Edit *e = &l->items[slots[i].seq];
        size_t pos = slots[i].pos;

        if (pos < cursor) {
            pos = cursor;                          /* never move backwards */
        }
        if (buf_add(&out, src + cursor, pos - cursor) != 0) goto fail;
        cursor = pos;

        if (e->kind == EDIT_INSERT && strcmp(e->inserted, "}") == 0) {
            /* a closing brace gets its own line */
            if (out.len > 0 && out.p[out.len - 1] != '\n' && buf_add(&out, "\n", 1) != 0) goto fail;
            if (buf_add(&out, e->before_eof ? "}\n" : "}", e->before_eof ? 2 : 1) != 0) goto fail;
        } else if (e->kind != EDIT_DELETE) {
            if (buf_add(&out, e->inserted, strlen(e->inserted)) != 0) goto fail;
        }
        if (e->kind != EDIT_INSERT) {              /* delete/replace remove the old token */
            size_t end = pos + e->length;
            if (end > n) end = n;
            if (end > cursor) cursor = end;
        }
    }
    if (buf_add(&out, src + cursor, n - cursor) != 0) goto fail;
    free(slots);
    return out.p;

fail:
    free(slots);
    free(out.p);
    return NULL;
}