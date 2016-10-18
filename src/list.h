/******************************************************************************
 *
 * File Name: lista.h
 * COMMENTS:
 *		Structure and prototypes for type List, a 1st order
 *      abstract data type that is a container.
 *		Each variable of type List implements a node of list of void *.
 *
 *****************************************************************************/

#ifndef _LISTA_H
#define _LISTA_H

/* type definition for structure to hold list item */
typedef struct _List List;

List *init_list(void);
void prepend(List *head, void *payload);
void *get_item(List *p);
List *get_next(List *p);

int get_node_count(List *head);
void free_list(List *lp, void (*free_item)(void *this));

#endif
