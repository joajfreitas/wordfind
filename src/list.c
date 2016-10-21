/******************************************************************************
 *
 * File Name: list.c
 *
 * COMMENTS:
 * Implements singly linked list with dummy head node
 *****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "list.h"
#include "err.h"

/* Linked list  */
struct _List {
	void *payload;
	struct _List *next;
};

/******************************************************************************
 * ini_list ()
 *
 * Arguments: none
 * Returns: Dummy head node
 * Side-Effects: list is initialized
 *
 * Description: initializes list
 *
 *****************************************************************************/

List *init_list(void)
{
	List *head = (List *) malloc(sizeof(List));
	head->next = NULL;
	head->payload = NULL;
	return head;
}


/******************************************************************************
 * prepend ()
 *
 * Arguments: nome - void * to save in list node
 * Returns: List  *
 * Side-Effects: none
 *
 * Description: creates and prepends a new node to the list
 *****************************************************************************/

void prepend(List* head, void * payload) {
	List *new_node;

	new_node = (List*) emalloc(sizeof(List));
	new_node->payload = payload;
	new_node->next = head->next;
	head->next = new_node;
	return;
}


/******************************************************************************
 * get_item ()
 *
 * Arguments: payload- pointer to element
 * Returns: void *
 * Side-Effects: none
 *
 * Description: returns an void * from the list
 *
 *****************************************************************************/

void *get_payload(List *p) {
	return p->payload;
}


/******************************************************************************
 * get_next ()
 *
 * Arguments: p - pointer to element
 * Returns: pointer to next element in list
 * Side-Effects: none
 *
 * Description: returns a pointer to an element of the list
 *
 *****************************************************************************/

List *get_next(List *p) {
	return p->next;
}


/******************************************************************************
 * get_node_count ()
 *
 * Arguments: lp - pointer to list
 * Returns:  count of the number of items in list
 * Side-Effects: none
 *
 * Description: returns the number of items (nodes) in the list
 *
 *****************************************************************************/

int get_node_count(List *head) {
	List *aux;  /* auxiliar pointers to travel through the list */
	int count = 0;
	aux = head->next;

	for (aux = head; aux != NULL; aux = aux->next)
		count++;

	return count;
}

/******************************************************************************
 * free_list ()
 *
 * Arguments: lp - pointer to list
 * Returns:  (void)
 * Side-Effects: frees space occupied by list items
 *
 * Description: free list
 *
 *****************************************************************************/

void free_list(List *lp, void (*free_item)(void *this)) {
	List *aux, *newhead;  /* auxiliar pointers to travel through the list */

	for (aux = lp; aux != NULL; aux = newhead) {
		newhead = aux->next;
		free_item(aux->payload);
		free(aux);
	}

	return;
}

void print_payload(List *node)
{
	if (node != NULL && ((char *) node->payload))
		printf("%s\n", (char *) node->payload);
}
