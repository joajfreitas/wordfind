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


void la_free(Lists_Array *la, void (*free_item)(void *item))
{
	int i;

	for (i = 0; i < la->num_lists; i++) {
		l_free(la->lists[i], free_item);
	}

	free(la->lists);
    free(la->list_sizes);
	free(la);
}


void la_save_word(Lists_Array *la, char *word)
{
    List *aux;
    char *new_word;
	size_t word_len = strlen(word);

	/* Check if word is already saved */
    for (aux = l_get_next(la_get_list(la, word_len)); aux != NULL; aux = l_get_next(aux)) {
		/* TODO: há palavras repetidas ou não? */
        if (!strcmp(word, (char *) l_get_item(aux)))
            return;
    }

	new_word = (char *) emalloc((word_len+1) * sizeof(char));
	strcpy(new_word, word);
	/* Save new_word in the appropiate list (indexed by word_len) */
	l_prepend(la_get_list(la, word_len), new_word);
	la_get_sizes(la)[word_len]++;
}


void la_print_word(Lists_Array *l)
{
	int i;
	List *aux = NULL;
	for (i=0, aux = l->lists[0]; i < l->num_lists; i++, aux = l->lists[i]) {
		printf("Lista: %d\n", i);
		while (aux != NULL) {
			if (l_get_item(aux))
				printf("%s\n", (char *) l_get_item(aux));
			aux = l_get_next(aux);
		}
	}
}

/* Helpers */
int *la_get_sizes(Lists_Array *l)
{
    return l->list_sizes;
}

int la_get_num_lists(Lists_Array *l)
{
    return l->num_lists;
}

List *la_get_list(Lists_Array *la, int n)
{
	return la->lists[n];
}
