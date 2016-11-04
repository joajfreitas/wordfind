/* Singly linked list with dummy head node */
#include <string.h>
#include <stdbool.h>

#include "err.h"
#include "list.h"
#include "word.h"


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

void l_prepend(List *head, Item item)
{
	List *new_node = (List *) emalloc(sizeof(List));
	new_node->item = item;

	new_node->next = head->next;
	head->next = new_node;

	return;
}

List *l_mergesort(List *c, bool (*less)(Item a, Item b))
{
	/* TODO: cutoff insertion sort */
	List *a, *b;

	if (c == NULL || c->next == NULL) {
		return c;
	}

	a = c;
	b = c->next;

	while ((b != NULL) && (b->next != NULL)) {
		c = c->next;
		b = b->next->next;
	}

	b = c->next;
	c->next = NULL;

	return l_merge(l_mergesort(a, less), l_mergesort(b, less), less);
}

List *l_merge(List *a, List *b, bool (*less)(Item a, Item b))
{
	struct _List head;

	List *c = &head;

	while ((a != NULL) && (b != NULL)) {
		if (less(a->item, b->item)) {
			c->next = a;
			c = a;
			a = a->next;
		}
		else {
			c->next = b;
			c = b;
			b = b->next;
		}
	}
	c->next = (a == NULL) ? b : a;

	/* TODO: WTF? */
	/*assert(c->next == head.next);*/

	return head.next;
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
