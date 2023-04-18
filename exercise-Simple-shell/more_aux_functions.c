#include "shell.h"

int
forkProcess(char **arguments)
{
	int status = 0;

	((fork() == 0) ? execve(arguments[0], arguments, environ) : wait(&status));
	return (WEXITSTATUS(status));
}
