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

char *find_command_path(char *env_path, char *command)
{
	char *path_copy = NULL, *path_token = NULL, *file_path_buffer = NULL;
	int command_len = 0, dir_len = 0;
	struct stat buffer;

	path_copy = strdup(env_path);
	command_len = strlen(command);
	path_token = strtok(path_copy, ":");

	while (path_token)
	{
		dir_len = strlen(path_token);
		file_path_buffer = malloc(command_len + dir_len + 2);
		if (!file_path_buffer)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(file_path_buffer, path_token);
		strcat(file_path_buffer, "/");
		strcat(file_path_buffer, command);
		strcat(file_path_buffer, "\0");

		if (stat(file_path_buffer, &buffer) == 0)
		{
			free(path_copy);
			return (file_path_buffer);
		}
		else
		{
			free(file_path_buffer);
			path_token = strtok(NULL, ":");
		}
	}
	free(path_copy);
	return (NULL);
}
