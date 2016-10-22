/* Singly linked list with dummy head node */
#include "list.h"
#include "err.h"


struct _List {
	Item item;
	struct _List *next;
};


List *l_init(void)
{
	List *head = (List *) emalloc(sizeof(List));
	head->next = NULL;
	head->item = NULL;

	return head;
}


void l_prepend(List *head, Item item)
{
	List *new_node = (List *) emalloc(sizeof(List));
	new_node->item = item;

	new_node->next = head->next;
	head->next = new_node;

	return;
}


void l_free(List *head, void (*free_item)(Item))
{
	List *aux = head->next;
	List *tmp;

	free(head);
	while (aux) {
		tmp = aux;
		aux = aux->next;
		free_item(tmp->item);
		free(tmp);
	}
}

/* Funções acessoras */
List *l_get_next(List *l)
{
	return l->next;
}

Item l_get_item(List *l)
{
	return l->item;
}


/* TESTE
void str_free(Item s)
{
	s = (char *) s;
	free(s);
}

int main(void)
{
	List *l = l_init();

	char *a = (char *) malloc(10*sizeof(char));
	char *b = (char *) malloc(10*sizeof(char));
	char *c = (char *) malloc(10*sizeof(char));
	strcpy(a, "hallo");
	strcpy(b, "hello");
	strcpy(c, "hillo");

	l_prepend(l, a);
	l_prepend(l, b);
	l_prepend(l, c);

	List *aux = l->next;
	while (aux) {
		printf("%s\n", (char *) l_get_item(aux));
		aux = aux->next;
	}

	l_free(l, str_free);
	return 0;
}
*/
