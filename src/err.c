#include <stdio.h>
#include <stdlib.h>
#include "err.h"

/*
 * TODO: Decidir error-checking por malloc ou wrapper
 * TODO: se por malloc lembrar de checkar TODOS os mallocs
*/

void err(char *error_message) {
	puts(error_message);
	exit(EXIT_FAILURE);
	return;
}
