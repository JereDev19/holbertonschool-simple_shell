#include "shell.h"
#define MAX_ARGS 300
#define BUFFER_SIZE 1024

int main(void)
{
	ssize_t chars_read = 0;
	size_t sizeBuffer = BUFFER_SIZE;
	char *command = NULL, *comandPathCopy = NULL, *token = NULL;
	char **args = NULL;
	int status = 0;

	char *bufferEntry = malloc(sizeof(char) * sizeBuffer);
	if (!bufferEntry)
		return (2);
	while (1)
	{
		int i = 0, b = 1;
		(isatty(STDOUT_FILENO) == 1 ? write(1, "$ ", 2) : 0);
		chars_read = getline(&bufferEntry, &sizeBuffer, stdin);
		comandPathCopy = strdup(bufferEntry);
		token = strtok(comandPathCopy, "\t \n");
		while (token)
			b++, token = strtok(NULL, "\t \n");
		char **args = malloc(sizeof(char *) * b);
		if (!args)
			return (2);
		args[i++] = strtok(bufferEntry, "\t \n");
		while (i < b)
			args[i] = strtok(NULL, " \n"), i++;
		
		if (chars_read == -1 || strcmp(bufferEntry, "exit\n") == 0)
			((bufferEntry) ? free(bufferEntry), exit(0) : 0);
		else if (strcmp(bufferEntry, "env\n") == 0)
			print_env();
		else
		{
			command = get_path(args[0]);
			if (command)
			{
				pid_t child = fork();
				((child > 0) ? wait(&status) : (child == 0) ? execve(command, args, environ) 
				: perror("Error"), (1));
				free(command);
			}
		}
		free(args);
		free(comandPathCopy);
	}
}
