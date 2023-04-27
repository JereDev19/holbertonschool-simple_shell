#include "shell.h"
/**
 * get_path - function that return the whole path of a given command
 * @command: given command
 * Return: whole path of the command
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len, dir_len;
	struct stat buffer;

	if (_getenv("PATH1"))
		path = _getenv("PATH1");
	else
		path = _getenv("PATH");
	
	if (!path)
		return (NULL);
	else if (path)
	{
		path_copy = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_copy, ":");

		while (path_token != NULL)
		{
			dir_len = strlen(path_token);
			file_path = malloc(command_len + dir_len + 2);
			if (!file_path)
			{
				free(path_copy), free(path);
				return (NULL);
			}
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy), free(path);
				return (file_path);
			}
			else
				free(file_path), path_token = strtok(NULL, ":");
		}
		free(path_copy), free(path);
		return (NULL);
	}
	return (NULL);
}