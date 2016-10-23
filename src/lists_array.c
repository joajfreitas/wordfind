#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "list.h"
#include "lists_array.h"


struct _Lists_Array {
	List **lists;
	int *list_sizes;
	int num_lists;
};


Lists_Array *la_init(int num_lists_init)
{
	int i;

	Lists_Array *la = (Lists_Array *) emalloc(sizeof(Lists_Array));

	la->list_sizes = (int *) emalloc(num_lists_init * sizeof(int));
	la->lists = (List **) emalloc(num_lists_init * sizeof(List *));
	la->num_lists = num_lists_init;

	for (i = 0; i < num_lists_init; i++) {
		la->lists[i] = l_init();
		la->list_sizes[i] = 0;
	}

	return la;
}

/* The index of the array depends on what the Item is,
 * so we need a function to find that
 */
void la_new_node(Lists_Array *la, Item item, int (*get_key)(Item))
{
    /*Se necessario verificar se a palavra ja existe*/
    int key = get_key(item);
    l_prepend(la->lists[key], item);
    la_get_sizes(la)[key]++;
}

void la_free(Lists_Array *la, void (*free_item)(Item item))
{
	int i;

	for (i = 0; i < la->num_lists; i++) {
		l_free(la->lists[i], free_item);
	}

	free(la->lists);
    free(la->list_sizes);
	free(la);
}

void la_print_lists(Lists_Array *l)
{
	int i;
	List *aux = NULL;
	for (i=0, aux = l->lists[0]; i < l->num_lists; i++) {
		printf("Lista: %d\n", i);
		while (aux != NULL) {
			if (l_get_item(aux))
				printf("%s\n", (char *) l_get_item(aux));
			aux = l_get_next(aux);
		}
        aux = l->lists[i];
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
