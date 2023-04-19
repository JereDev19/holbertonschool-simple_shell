#include "shell.h"

int main(void)
{
	ssize_t chars_read = 0;
	size_t sizeBuffer = 0;
	char *bufferEntry = NULL, *comandPath = NULL, *command = NULL, *token = NULL;
	int status = 0, i = 0;

	bufferEntry = malloc(sizeof(char) * sizeBuffer);
	if (!bufferEntry)
		return (2);

	while (1)
	{
		(isatty(STDOUT_FILENO) == 1 ? write(1, "$ ", 2) : 0);
		chars_read = getline(&bufferEntry, &sizeBuffer, stdin);
		token = strtok(bufferEntry, "\t \n");
		
		char **args = malloc(sizeof(char *) * sizeBuffer);
		if (!args)
			return (2);

		while (token != NULL) 
		{
			args[i] = token;
			token = strtok(NULL, " \n");
 			i++;
		}
		/* -- Verify if the command is exit or the user place exit --*/
		if (chars_read == -1 || strcmp(bufferEntry, "exit\n") == 0)
			((bufferEntry) ? free(bufferEntry), exit(status) : 0);
		
		else if (strcmp(bufferEntry, "env\n") == 0)
			print_env();

		/*path copy so not modify the original buffer*/
		comandPath = strdup(bufferEntry);
		command = get_path(comandPath);

		if (command != NULL)
		{
			pid_t child = fork();
		
			if (child > 0)
			{
				wait(&status);
			}
			else if (child == 0)
			{
				execve(command, args, environ);
			}
			else
			{
				perror("Error");
				return (1);
			}
		free(comandPath);
		free(args[0]);
		free(args);
		}
	}
}
