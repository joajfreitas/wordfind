/******************************************************************************
 *
 * File Name: dict.c
 *
 * COMMENTS:
 * Implements an array of lists that store words read from a file
 * The number of the words in a list is the index which points to that list
 *****************************************************************************/

#include <stdlib.h>
#include "const.h"
#include "err.h"
#include "lists_array.h"
#include "list.h"


struct _lists_array {
	List **lists; /* MAX_WORD_SIZE lists */
	int *list_sizes[MAX_WORD_SIZE];
};

Lists_Array *init_lists_array()
{
	int i;

	Lists_Array *l = (Lists_Array *) malloc(sizeof(Lists_Array));
	if (l == NULL)
		err("Impossivel alocar memoria para Array de Listas");

	l->lists = (List **) malloc(MAX_WORD_SIZE * sizeof(List *));
	if (l->lists == NULL)
		err("Impossivel alocar memoria para Lista de Listas de palavras");

	for (i = 0; i < MAX_WORD_SIZE; i++) {
		l->lists[i] = init_list();
		l->list_sizes[i] = 0;
	}

	return l;
}

void free_lists_array(Lists_Array *l, void (*free_item)(void *this))
{
	int i;

	for (i = 0; i < MAX_WORD_SIZE; i++)
		free_list(l->lists[i], free_item);

	free(l->lists);
	free(l);

	return;
}
