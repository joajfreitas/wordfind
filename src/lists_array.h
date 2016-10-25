#ifndef _LISTS_ARRAY_H
#define _LISTS_ARRAY_H

#include "list.h"

typedef struct _Lists_Array Lists_Array;

Lists_Array *la_init(int num_lists_init);
void la_free(Lists_Array *la, void (*free_item)(Item item));

void la_new_node(Lists_Array *la, Item item, int index);
void la_print_lists(Lists_Array *l);

int *la_get_sizes(Lists_Array *l);
int la_get_num_lists(Lists_Array *l);
List *la_get_list(Lists_Array *la, int n);
void la_convert_to_array(Lists_Array *la);
void print_array(Lists_Array *la);

#endif
