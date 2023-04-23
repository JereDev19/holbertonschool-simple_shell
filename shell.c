#include "shell.h"

/**
* main - replicate of a shell.
* @argc: number of params.
* @argv: array with values of paramams.
* Return:  return exit status of last program.
*/

int main(int argc, char *argv[])
{
	size_t sizeBuffer = 0;
	char *command = NULL, *bufferEntry = NULL, **args = NULL;
	int status = 0, satty = isatty(STDOUT_FILENO), count = 0;
	(void)argc;
	satty == 1 ? write(1, "$ ", 2) : 0;

	while (getline(&bufferEntry, &sizeBuffer, stdin) >= 0)
	{
		count += 1;
		if (strlen(bufferEntry) == 1)
		{
			satty == 1 ? write(1, "$ ", 2) : 0;
			continue;
		}
		if (strcmp(bufferEntry, "exit\n") == 0)
		{
			free(bufferEntry);
			exit(status);
		}
		args = generate_args(bufferEntry);
		if (!args)
			return (2);
		if (strcmp(args[0], "env\n") == 0)
			print_env();
		else
		{
			command = get_path(args[0]);
			if (command)
			{
				status = forkProcess(command, args);
				free(command);
			}
			else
			{
				printErr(count, argv[0], bufferEntry);
				status = 127;
			}
		}
		free(args);
		satty == 1 ? write(1, "$ ", 2) : 0;
	}
	free(bufferEntry);
	return (status);
}
