#ifndef _LIST_H
#define _LIST_H

#include "item.h"




typedef struct _List List;
List *l_init(void);
void l_free(List *lp, void (*free_item)(Item));

void l_prepend(List *head, Item item);

int cmp(Item a, Item b);
List *l_mergesort(List *c);
List *merge(List *a, List *b);

Item l_get_item(List *p);
List *l_get_next(List *p);
void l_set_next(List *l, List *next);

#endif
