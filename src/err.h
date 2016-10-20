/******************************************************************************
 *
 * File Name: err.h
 * COMMENTS:
 *			Some tools to make error handling easier
 *
 *****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#ifndef _ERR_H
#define _ERR_H

void err(char *error_message);
void *emalloc(size_t size);
FILE *efopen(char *filename, char *mode);

#endif
