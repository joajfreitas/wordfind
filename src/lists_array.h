/******************************************************************************
 *
 * File Name: dict.h
 * COMMENTS:
 *
 *****************************************************************************/

#ifndef _DICT_H
#define _DICT_H

/* type definition for structure to hold word lists */
typedef struct _lists_array Lists_Array;

Lists_Array *init_lists_array();
void free_lists_array(Lists_Array *l, void (*free_item)(void *this));
void write_to_dict(Lists_Array *l, char *word);
void print_dict(Lists_Array *l);

#endif
