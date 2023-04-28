#include "shell.h"

/**
 * print_env - print enviroment.
 */
void print_env(void)
{
	int i = 0;

	if (!environ)
		return;

	for (; environ[i]; i++)
		printf("%s\n", environ[i]);
}