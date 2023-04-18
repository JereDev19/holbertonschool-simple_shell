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
	int i = 0, len_name = 0;
	char *buffer = NULL, *tokens = NULL;

	buffer = malloc(sizeof(char *) * environ);

	if (!name || !buffer)
		return (NULL);

	while (environ[i])
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
				free(buffer);
				return (strdup(tokens));
			}
			free(buffer);
		}
		free(buffer);
		i++;
	}
	return (NULL);
}

/**
 * print_path - Write a function that prints each directory of the PATH.
 */

void print_path(void)
{
	unsigned int i = 0;
	char *env = _getenv("PATH"), *dir;

	if (!env)
		return;

	dir = strtok(env, ":");

	while (dir)
	{
		printf("%s\n", dir);
		dir = strtok(NULL, ":");
	}
}


int
forkProcess(char **arguments)
{
	int status = 0;

	((fork() == 0) ? execve(args[0], arguments, environ) : wait(&status));
	return (WEXITSTATUS(status));
}
