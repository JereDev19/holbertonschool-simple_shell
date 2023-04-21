#include "shell.h"

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
		free(arguments);
		perror("SE PUDRIO TODO, LA TENSA");
	}
	return (WEXITSTATUS(status));
}
