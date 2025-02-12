#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "const.h"
#include "list.h"
#include "lists_array.h"


struct _Lists_Array {
	Item ***array;
	List **lists;
	/* Tamanho de cada lista */
	int *list_sizes;
	/* Tamanho do array de listas */
	int num_lists;
	/* A cada tamanho de palavra faz corresponder o endereço real
	 * na tabela de listas */
	int *index;
};


Lists_Array *la_init(int *word_sizes)
{
	int i;
	int lists_length = 0;

	Lists_Array *la = (Lists_Array *) emalloc(sizeof(Lists_Array));

	la->index = (int *) emalloc(MAX_WORD_SIZE * sizeof(int));
	memcpy(la->index, word_sizes, MAX_WORD_SIZE * sizeof(int));

	lists_length = la_get_lists_length(la) + 1;

	la->list_sizes = (int *) emalloc(lists_length * sizeof(int));
	la->lists = (List **) emalloc(lists_length * sizeof(List *));
	la->array = (Item ***) emalloc(lists_length * sizeof(Item **));


	la->num_lists = lists_length;

	for (i = 0; i < lists_length; i++) {
		la->lists[i] = l_init();
		la->list_sizes[i] = 0;
	}

	return la;
}

void la_new_node(Lists_Array *la, Item item, int index)
{
	l_prepend(la->lists[la_get_adjusted_index(la, index)], item);
	la_get_sizes(la)[la_get_adjusted_index(la, index)]++;
}

void la_free(Lists_Array *la, void (*free_item)(Item item))
{
	int i;

	for (i = 0; i < la->num_lists; i++) {
		l_free(la->lists[i], free_item);
	}

	for (i = 0; i < la->num_lists; i++) {
		free(la->array[i]);
	}
	free(la->array);
	free(la->lists);
	free(la->list_sizes);
	free(la->index);
	free(la);
}


void la_sort_lists(Lists_Array *la, bool (*less)(Item a, Item b))
{
	int i;
	List *sorted;
	for (i = 0; i < la->num_lists; i++) {
		/* lista tem dummy head node */
		sorted = l_mergesort(l_get_next(la->lists[i]), less);
		/* Substituir lista antiga pela ordenada */
		l_set_next(la->lists[i], sorted);
	}
}

void la_convert_to_array(Lists_Array *la)
{
	int i, j;
	List *aux = NULL;
	Item **array;

	for (i = 0; i < la->num_lists; i++)	{
		array = (Item **) emalloc(sizeof(Item *) * la->list_sizes[i]);
		aux = l_get_next(la->lists[i]);

		for (j=0; aux != NULL; j++) {
			array[j] = l_get_item(aux);
			aux = l_get_next(aux);
		}

		la->array[i] = array;
	}
}

int la_binary_search(Lists_Array *la, char *word)
{
	int index = strlen(word);
	int adjusted_index = la_get_adjusted_index(la, index);

	int R = la->list_sizes[adjusted_index] - 1;
	int L = 0;
	int m = (L+R)/2;
	int j;

	while ((j = strcmp(word, (char *) la->array[adjusted_index][m])) != 0) {
		if (L>R)
			return 0;
		else if (j<0)
			R = m-1;
		else if (j>0)
			L = m+1;

		m = (L + R)/2;
	}

	return m;
}

/* TODO: Only for debug remove before deliver */
void print_array(Lists_Array *la)
{
	int i, j;
	for (i=0; i < la->num_lists; i++) {
		printf("\nArray: %d\n\n", i);

		for (j=0; j < la->list_sizes[i]; j++) {
			if (la->array[i][j] == NULL)
				break;
			printf("%s\n", (char *) la->array[i][j]);
		}
	}
}


/* Funções acessoras */
int *la_get_sizes(Lists_Array *la)
{
	return la->list_sizes;
}

int la_get_num_lists(Lists_Array *la)
{
	return la->num_lists;
}

List *la_get_list(Lists_Array *la, int n)
{
	return la->lists[n];
}

int la_get_index(Lists_Array *la, int index)
{
	return la->index[index];
}

int la_get_lists_length(Lists_Array *la)
{
	int i;
	int counter = 0;
	for (i = 0; i < MAX_WORD_SIZE; i++)
		if (la->index[i])
			counter++;

	return counter;
}

int la_get_adjusted_index(Lists_Array *la, int index)
{
	return la->index[index];
}
