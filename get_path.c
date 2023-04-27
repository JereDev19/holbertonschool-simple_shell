#include "shell.h"
/**
 * get_path - function that return the whole path of a given command
 * @command: given command
 * Return: whole path of the command
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path, *env_path1 = _getenv("PATH1"), *env_path = _getenv("PATH");
	int command_len, dir_len;
	struct stat buffer;

	if (env_path1 != NULL && strlen(env_path1) > 0)
		path = env_path1;
	else if (env_path != NULL && strlen(env_path) > 0)
		path = env_path;
	else
		path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
		
	if (path)
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