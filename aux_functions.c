#include "shell.h"

/**
 * print_env - print enviroment.
 *
 * Exercise 0.
 */

void print_env(void)
{
	int i;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
}

char
**generate_args(char *param)
{
	int i = 0, lenthPath = 1;
	char *commandPathCopy = NULL, *token = NULL;
	char *delimiters = NULL, **args = NULL;

	delimiters = "\t \n";

	commandPathCopy = strdup(param);
	if (!commandPathCopy)
		return (NULL);

	token = strtok(commandPathCopy, delimiters);
	while (token)
		token = strtok(NULL, delimiters), lenthPath++;

	args = malloc(sizeof(char *) * lenthPath);
	if (!args)
	{
		free(commandPathCopy);
		return (NULL);
	}
	args[i++] = strtok(param, delimiters);

	while (i < lenthPath)
	{
		args[i] = strtok(NULL, delimiters);
		i++;
	}

	free(commandPathCopy);
	return (args);
}

/**
 * _getenv - Get a environment variable.
 *
 * @name: name of environment variable.
 * Return: environment variable.
 *
 * Exercise 2..
 */

char *_getenv(const char *name)
{
	char *buffer = NULL, *token = NULL;
	int i = 0, b = 0, environ_size = 0;

	for (; environ[b]; b++)
		environ_size++;

	buffer = malloc(sizeof(char) * (environ_size + 1));
	if (!buffer)
		return (NULL);

	for (; environ[i]; i++)
	{
		free(buffer);
		buffer = strdup(environ[i]);
		buffer = strtok(buffer, "=");
		if (strcmp(buffer, name) == 0)
		{
			token = strdup(strtok(NULL, "="));
			free(buffer);
			return (token);
		}
	}
	free(buffer);
	return (NULL);
}
