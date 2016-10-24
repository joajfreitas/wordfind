#ifndef _WORD_H
#define _WORD_H

#include "item.h"

/* TODO:
 * typedef struct _Word Word
 */

char *w_new(char *word);
void w_free(Item word);

int w_get_size(char *word);

#endif
