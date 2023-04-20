#include "shell.h"
#define MAX_ARGS 300
#define BUFFER_SIZE 1024

int main(void)
{
	size_t sizeBuffer = BUFFER_SIZE;
	char *command = NULL, *comandPathCopy = NULL, *token = NULL, **args = NULL, *bufferEntry = NULL;
	int status = 0, satty = isatty(STDOUT_FILENO);

	bufferEntry = malloc(sizeof(char) * sizeBuffer);
	if (!bufferEntry)
		return (2);
	
	satty == 1 ? write(1, "$ ", 2) : 0;

	while (getline(&bufferEntry, &sizeBuffer, stdin) >= 0)
	{
		if (strcmp(bufferEntry, "exit\n") == 0)
			break;
		args = generate_args(bufferEntry);
		if (!args)
			return (2);
		if (strcmp(bufferEntry, "env\n") == 0)
			print_env();
		else if (strcmp(bufferEntry, "\n") == 0)
			satty == 1 ? write(1, "", 0) : 0;
		else
		{
			command = get_path(args[0]);
			if (command)
			{
				pid_t child = fork();
				if (child > 0)
					wait(&status);
				else if (child == 0)
					execve(command, args, environ);
				else
				{
					free(args);
					perror("Error");
					return (1);
				}
				free(command);
			}	
		}
		free(args);
		free(comandPathCopy);
		satty == 1 ? write(1, "$ ", 2) : 0;
	}
	free(bufferEntry);
	return (0);
}