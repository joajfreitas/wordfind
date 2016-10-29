/* Singly linked list with dummy head node */
#include "list.h"
#include "err.h"
#include <string.h>

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

int cmp(Item a, Item b)
{
	int cmp;
	cmp = strcmp((char *) a, (char *) b);
	if (cmp <= 0)
		return 1;
	else
		return 0; 

}

/*Perigo: passar head->next como argumento*/
List *l_mergesort(List *c)
{
	List *a, *b;
	/*printf("%s\n", (char *) c->item);*/
	if (c==NULL || c->next == NULL) return c;
	a = c; b = c->next;
	while ((b != NULL) && (b->next != NULL)) {
		c = c->next; 
		b = b->next->next;
	}

	b = c->next; c->next = NULL;
	return merge(l_mergesort(a), l_mergesort(b));
}

List *merge(List *a, List *b)
{
	struct _List head; List *c = &head;
	while ((a != NULL) && (b != NULL)) {
		if(cmp(a->item, b->item)) {
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
