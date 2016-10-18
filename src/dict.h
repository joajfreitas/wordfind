/******************************************************************************
 *
 * File Name: dict.h
 * COMMENTS:
 *
 *****************************************************************************/

#ifndef _DICT_H
#define _DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/* type definition for structure to hold list item */
typedef struct _Dict Dict;

Dict *init_dict(int list_count);
void free_dict(Dict *dict);
#endif
