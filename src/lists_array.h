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

Lists_Array *la_init();
void la_free(Lists_Array *l, void (*free_item)(void *this));
void la_write(Lists_Array *l, char *word);
void la_print(Lists_Array *l);

#endif
