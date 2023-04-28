#include "shell.h"

/**
* executeCommand - Execute a command
* - either an absolute path or a single command and un error message.
*
* @args: An array of arrays that contains the arguments.
* @count: Count of times that the user introduced a command.
* @bufferEntry: Entry of the user.
* @argv: Name of the program.
*
* Return: status.
**/

int executeCommand(char **args, int count, char *bufferEntry, char *argv[])
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
