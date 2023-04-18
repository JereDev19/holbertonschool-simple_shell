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

void
print_env_environ(int argc, char **ar, char **env)
{
	printf("Adress of env: %p\n", (void *)env);
	printf("Addres of environ: %p\n", (void *)environ);
}

char
*_getenv(const char *name)
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
