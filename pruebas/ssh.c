#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	pid_t my_pid;

	char *filename = "/bin/ls";
	char *argv[] = {"ls", "-l", "/tmp", NULL};

	for (int i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0)
		{
			my_pid = getpid();
			printf("Id del hijo: %d\n", my_pid);
			my_pid = getppid();
			printf("Id del padre: %d\n", my_pid);
			if (execve(filename, argv, NULL) == -1)
			{
				perror("execve error");
				exit(1);
			}
			return (1);
		}
		else
		{
			wait(NULL);
		}
	}
	return (0);
}
