#include "shell.h"

/**
 * print_env - print enviroment.
 */
void print_env(void)
{
	int i = 0;
	char **environ_copy = NULL;
	
	environ_copy = environ;

	if (!environ_copy || !environ)
		return;

	for (; environ_copy[i]; i++)
	{
		puts(environ_copy[i]);
		putchar('\n');
	}
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
 * @name: name of environment variable.
 * Return: environment variable.
 */
char *_getenv(const char *name)
{
	char *buffer = NULL, *token = NULL;
	int i = 0, environ_size = 0;

	for (; environ[environ_size]; environ_size++)
		;

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
