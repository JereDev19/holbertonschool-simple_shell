#include "shell.h"

/**
 * free_array - frees an array.
 * @param: array to free.
 */

void free_array(char **param)
{
	int i = 0;

	for (; param[i]; i++)
		free(param[i]);
	free(param);
}