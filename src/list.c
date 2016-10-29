/* Singly linked list with dummy head node */
#include "list.h"
#include "err.h"





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

void l_set_next(List *l, List *next)
{
	l->next = next;
}
