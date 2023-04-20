#include "shell.h"

/**
 * print_env - print enviroment.
 *
 * Exercise 0.
 */

void print_env(void)
{
	int i = 0;

	if (!environ)
		return;

	for (; environ[i]; i++)
		printf("%s\n", environ[i]);
}

/**
 * print_path - Write a function that prints each directory of the PATH.
 */

void print_path(void)
{
	unsigned int i = 0;
	char *env = _getenv("PATH"), *dir;

	while (env)
	{
		printf("%s\n", env);
		env = strtok(NULL, ":");
	}
}

char
**generate_args(char *param)
{
	int i = 0, b = 0;
	char *commandPathCopy = NULL, *token = NULL, *delimiters = NULL, **args = NULL;
	
	delimiters = "\t \n";

	commandPathCopy = strdup(param);
	if (!commandPathCopy)
		return (NULL);

	token = strtok(param, delimiters);	
	while (token)
	{
		b++;
		token = strtok(NULL, delimiters);
	}
	args = malloc(sizeof(char *) * b);
	if (!args)
	{
		free(commandPathCopy);
		return (NULL);
	}

	args[i++] = strtok(param, delimiters);
	while (i < b)
	{
		i++, args[i] = strtok(NULL, delimiters);
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
	char *buffer = NULL, *token = NULL, **environ_copy = environ;
	int i = 0, b = 0, environ_size = 0;

	for (; environ_copy[b]; b++)
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