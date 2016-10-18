/******************************************************************************
 *
 * File Name: dict.c
 *
 * COMMENTS:
 * Implements an array of lists to store words read from a file
 * The length of the words in a list is equal to the index which points to
 * that list
 *****************************************************************************/

#include <stdlib.h>
#include "dict.h"
#include "list.h"
#include "err.h"

/* pointer struct */
struct _Dict {
	List **lists;
	int *node_count;
	int array_size;
};

Dict *init_dict(int list_count)
{
	int i;

	Dict *dict = (Dict *) malloc(sizeof(Dict));
	if (dict == NULL)
		err("Impossivel alocar memoria para struct dicts");
	
	dict->array_size = list_count;
	dict->node_count = (int *) malloc(list_count * sizeof(int));

	dict->lists = (List **) malloc(list_count * sizeof(List*));
	if (dict->lists == NULL)
		err("Impossivel alocar memoria para array de listas");
	for (i=0; i<list_count; i++) {
		dict->lists[i] = init_list();
		dict->node_count[i] = 0;

	}

	return dict;
}

void free_item(void *this) {
	return;
}
void free_dict(Dict *dict)
{
	int i=0;
	for (i = 0; i < dict->array_size; i++)
		free_list(dict->lists[i], free_item);
	free(dict->lists);
	free(dict->node_count);
	free(dict);
	return;
}

