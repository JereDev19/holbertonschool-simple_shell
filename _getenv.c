#include "shell.h"

/**
 * _getenv - Get a environment variable.
 * @name: name of environment variable.
 * Return: environment variable.
 */

char *_getenv(const char *name)
{
	char *bufferName = NULL, *token = NULL;
	int i = 0, environ_size = 0;

	for (; environ[environ_size]; environ_size++)
		;

	bufferName = malloc(sizeof(char) * (environ_size + 1));
	if (!bufferName)
		return (NULL);

	for (; environ[i]; i++)
	{
		free(bufferName);
		bufferName = strdup(environ[i]);
		bufferName = strtok(bufferName, "=");
		if (strcmp(bufferName, name) == 0)
		{
			token = strtok(NULL, "=");
			if (token && token[0] != '\0')
				token = strdup(token);
			free(bufferName);
			return (token);
		}
	}
	free(bufferName);
	return (NULL);
}
