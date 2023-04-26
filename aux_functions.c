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
