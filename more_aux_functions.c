#include "shell.h"

/**
* forkProcces - Function that execute a child process.
* @command: path of param.
* @arguments: arguments of the command.
* Return: status of child process.
*/
int
forkProcess(char *command, char **arguments)
{
	int status = 0;

	pid_t child = fork();

	if (child > 0)
	{
		wait(&status);
	}
	else if (child == 0)
	{
		execve(command, arguments, environ);
	}
	else
	{
		free_array(arguments);
		perror("Error:");
	}
	return (WEXITSTATUS(status));
}

void
printErr(int count, char *name, char *bufferEntry)
{
	fprintf(stderr, "%s: %d: %s: not found\n", name, count, bufferEntry);
}

/**
 * free_array - frees an array.
 * @param: array to free.
 */
void free_array(char **param)
{
	int i = 0;

	for (; param[i]; i++)
		free(param[i]);
	free(param);
}

int
executeCommand(char **args, int count, char *bufferEntry, char *argv[])
{
	struct stat buffer;
	char *command;
	int status;

	if (stat(args[0], &buffer) == 0)
	{
		command = args[0];
		status = forkProcess(command, args);
	}
	else if (stat(args[0], &buffer) == -1)
	{
		command = get_path(args[0]);
		if (command)
		{
			status = forkProcess(command, args);
			free(command);
			if (status == -1)
				status = 2; /* if forkProcess fails, status is 2 */
		} else
		{
			printErr(count, argv[0], bufferEntry);
			status = 127;
		}
	}
	return (status);
}
