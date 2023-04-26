#include "shell.h"

/**
 * get_path - function that return the whole path of a given command
 * @command: given command
 * Return: whole path of the command
 */

char *get_path(char *command)
{
	char *path, *file_path_return;

	path = _getenv("PATH");
	file_path_return = find_command_path(path, command);
	
	if (file_path_return)
		return (file_path_return);
	
	path = _getenv("PATH1");
	file_path_return = find_command_path(path, command);

	return (file_path_return);
}
