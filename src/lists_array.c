#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "list.h"
#include "lists_array.h"


struct _Lists_Array {
	Item ***array;
	List **lists;
	int *list_sizes;	/*Tamanho de cada lista*/
	int num_lists;		/*Tamanho do array de listas*/
	int *index;			/*A cada tamanho de palavra faz corresponder o endereço real na tabela de listas*/
};

Lists_Array *la_init(int *index_init)
{
	int i;
	int lists_length = 0;

	Lists_Array *la = (Lists_Array *) emalloc(sizeof(Lists_Array));

	la->index = (int *) ecalloc(MAX_WORD_SIZE, sizeof(int));
	memcpy(la->index, index_init, MAX_WORD_SIZE*sizeof(int));

	lists_length = la_get_lists_lenght(la) + 1;

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
	l_prepend(la->lists[la_get_ajusted_index(la, index)], item);
	la_get_sizes(la)[la_get_ajusted_index(la, index)]++;
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
	free(la->index);	
	free(la);
}

void la_convert_to_array(Lists_Array *la) 
{
	int i, j;
	List *aux = NULL;

	for (i = 0; i < la->num_lists; i++)	{
		Item **array = (Item **) emalloc(sizeof(Item *) * la->list_sizes[i]);
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

int la_get_index(Lists_Array *la, int index)
{
	return la->index[index];
}

int la_get_lists_lenght(Lists_Array *la)
{
	int i;
	int counter = 0;
	for (i = 0; i < MAX_WORD_SIZE; i++)
		if (la->index[i])
			counter++;

	return counter;
}

int la_get_ajusted_index(Lists_Array *la, int index)
{
	return la->index[index];
}
