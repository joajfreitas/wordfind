#ifndef _LISTS_ARRAY_H
#define _LISTS_ARRAY_H

#include "list.h"

typedef struct _Lists_Array Lists_Array;

Lists_Array *la_init(int *word_exists);
void la_free(Lists_Array *la, void (*free_item)(Item item));

void la_new_node(Lists_Array *la, Item item, int index);
void la_print_lists(Lists_Array *l);

void la_convert_to_array(Lists_Array *la);
void la_sort_lists(Lists_Array *la);
int la_binary_search(Lists_Array *la, char *word);
void print_array(Lists_Array *la);

int *la_get_sizes(Lists_Array *la);
int la_get_num_lists(Lists_Array *la);
List *la_get_list(Lists_Array *la, int n);
int la_get_index(Lists_Array *la, int index);
int la_get_lists_length(Lists_Array *la);
int la_get_adjusted_index(Lists_Array *la, int index);

#endif
