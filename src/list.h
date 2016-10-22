#ifndef _LIST_H
#define _LIST_H

#define Item void*
typedef struct _List List;

List *l_init(void);
void l_free(List *lp, void (*free_item)(Item));

void l_prepend(List *head, Item item);

Item l_get_item(List *p);
List *l_get_next(List *p);

#endif
