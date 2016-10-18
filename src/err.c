#include <stdio.h>
#include <stdlib.h>
#include "err.h"

void err(char *error_message) {
		puts(error_message);
		exit(EXIT_FAILURE);
	return;
}
