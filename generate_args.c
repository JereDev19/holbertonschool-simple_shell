#include "shell.h"

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