#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "list.h"
#include "lists_array.h"


struct _Lists_Array {
	List **lists;
	Item ***array;
	int *list_sizes;
	int num_lists;
};

Lists_Array *la_init(int num_lists_init)
{
	int i;

	Lists_Array *la = (Lists_Array *) emalloc(sizeof(Lists_Array));

	la->list_sizes = (int *) emalloc(num_lists_init * sizeof(int));
	la->lists = (List **) emalloc(num_lists_init * sizeof(List *));
	la->array = (Item ***) emalloc(num_lists_init * sizeof(Item **));
	la->num_lists = num_lists_init;

	for (i = 0; i < num_lists_init; i++) {
		la->lists[i] = l_init();
		la->list_sizes[i] = 0;
	}

	return la;
}

void la_new_node(Lists_Array *la, Item item, int index)
{
	l_prepend(la->lists[index], item);
	la_get_sizes(la)[index]++;
}

void la_free(Lists_Array *la, void (*free_item)(Item item))
{
	int i;

	for (i = 0; i < la->num_lists; i++) {
		l_free(la->lists[i], free_item);
	}

	for (i = 0; i < la->num_lists; i++)
	{
		free(la->array[i]);
	}
	free(la->array);
	free(la->lists);
	free(la->list_sizes);	
	free(la);
}

void la_convert_to_array(Lists_Array *la) 
{
	int i, j;
	List *aux = NULL;
	for (i = 0; i < la->num_lists; i++)	{
		Item **array = (Item **) malloc(sizeof(Item *) * la->list_sizes[i]);
		aux = l_get_next(la->lists[i]);
		for (j=0; aux != NULL; j++) {
			array[j] = l_get_item(aux);
			aux = l_get_next(aux);			
		}
		la->array[i] = array;
	}
}

void print_array(Lists_Array *la)
{
	int i, j;
	for (i=0; i < la->num_lists; i++) {
		for (j=0; j < la->list_sizes[i]; j++)
		{
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

/* TODO: this is not very orthogonal */
List *la_get_list(Lists_Array *la, int n)
{
	return la->lists[n];
}
