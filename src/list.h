#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

#include "item.h"

typedef struct _List List;

List *l_init(void);
void l_free(List *lp, void (*free_item)(Item));

void l_prepend(List *head, Item item);

List *l_mergesort(List *c, bool (*less)(Item a, Item b));
List *l_merge(List *a, List *b, bool (*less)(Item a, Item b));

Item l_get_item(List *l);
List *l_get_next(List *l);
void l_set_next(List *l, List *next);

#endif
