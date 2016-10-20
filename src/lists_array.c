/******************************************************************************
 *
 * File Name: dict.c
 *
 * COMMENTS:
 * Implements an array of lists that store words read from a file
 * The number of the words in a list is the index which points to that list
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include "err.h"
#include "list.h"
#include "lists_array.h"

struct _lists_array {
	List **lists; /* MAX_WORD_SIZE lists */
	int *lists_sizes;
	int num_lists;
};

Lists_Array *init_lists_array(int num_lists_init)
{
	int i;

	Lists_Array *l = (Lists_Array *) emalloc(sizeof(Lists_Array));
	if (l == NULL)
		err("Impossivel alocar memoria para Array de Listas");

	l->lists_sizes = (int *) emalloc(num_lists_init * sizeof(int));
	l->lists = (List **) emalloc(num_lists_init * sizeof(List *));
	l->num_lists = num_lists_init;

	for (i = 0; i < num_lists_init; i++) {
		l->lists[i] = init_list();
		l->lists_sizes[i] = 0;
	}

	return l;
}

void free_lists_array(Lists_Array *l, void (*free_item)(void *this))
{
	int i;

	for (i = 0; i < l->num_lists; i++)
		free_list(l->lists[i], free_item);

	free(l->lists);
	free(l);

	return;
}

void write_to_dict(Lists_Array *l, char *word)
{
	size_t word_len = strlen(word);
	char *payload = (char *) emalloc((word_len+1) * sizeof(char));
	payload = strcpy(payload, word);
	prepend(l->lists[(int) word_len], payload);
	(l->lists_sizes[(int) word_len])++;
}

void print_dict(Lists_Array *l)
{
	int i;
	List *aux = NULL;
	/*printf("%d\n", l->lists_sizes[	*/
	for (i=0, aux = l->lists[0]; i < l->num_lists; aux = l->lists[i], i++) {
		printf("Percorri o dict %d vezes\n", i);
		while(aux != NULL) {
			if (get_payload(aux))
				printf("%s\n", (char *) get_payload(aux));
			aux = get_next(aux);
		}
	}
}
	
