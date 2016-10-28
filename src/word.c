#include <stdlib.h>
#include <string.h>

#include "err.h"
#include "word.h"

/* TODO:
 *
 * struct _Word {
 *	char *word;
 * };
 *
*/
char *w_new(char *word)
{
	char *new_word = (char *) emalloc((strlen(word) + 1) * sizeof(char));
	strcpy(new_word, word);

	return new_word;
}

void w_free(Item word)
{
	free(word);
}

/* Funções acessoras */
int w_get_size(char *word)
{
	return (int) strlen(word);
}
