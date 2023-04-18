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

/**
 * print_env_environ - print env and environ.
 *
 * @argc: cant of arguments.
 * @ar: value of those arguments.
 * @env: environment of variable.
 *
 * Exercise 1.
 */

void print_env_environ(int argc, char **ar, char **env)
{
	printf("Adress of env: %p\n", (void *)env);
	printf("Addres of environ: %p\n", (void *)environ);
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
	int i = 0, len_name = 0, environ_size = 0;
	char *buffer = NULL, *tokens = NULL, *result;
	char **environ_copy = environ;

	while (environ_copy[environ_size] != NULL)
		environ_size++;

	buffer = malloc(sizeof(char *) * (environ_size + 1));

	if (!name || !buffer)
		return (NULL);

	for (; environ[i]; i++)
	{
		buffer = strdup(environ[i]);
		tokens = strtok(buffer, "=");

		/*Verify the name with the first ocurrence of = - (left side)*/
		if (strcmp(name, tokens) == 0)
		{
			/*To remain where it was found. Gets the value of that env*/
			tokens = strtok(NULL, "=");
			if (tokens)
			{
				result = strdup(tokens);
				free(buffer);
				return (result);
			}
			free(buffer);
		}
		free(buffer);
	}
	return (NULL);
}

int
forkProcess(char **arguments)
{
	int status = 0;

	((fork() == 0) ? execve(arguments[0], arguments, environ) : wait(&status));
	return (WEXITSTATUS(status));
}
