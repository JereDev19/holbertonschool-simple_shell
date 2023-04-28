#include "shell.h"

/**
 * main - replicate of a shell.
 * @argc: number of params.
 * @argv: array with values of paramams.
 * Return: return exit status of last program.
*/

int main(int argc __attribute__((unused)), char *argv[])
{
	size_t sizeBuffer = 0;
	char *bufferEntry = NULL, **args = NULL;
	int status = 0, satty = isatty(STDIN_FILENO), count = 0;

	satty == 1 ? write(1, "$ ", 2) : 0;
	while (getline(&bufferEntry, &sizeBuffer, stdin) >= 0)
	{
		count += 1;
		if (strlen(bufferEntry) == 1)
		{
			satty == 1 ? write(1, "$ ", 2) : 0;
			continue;
		}
		else if (strcmp(bufferEntry, "exit\n") == 0)
		{
			if (bufferEntry)
				free(bufferEntry);
			exit(status);
		}
		args = generate_args(bufferEntry);
		if (args && args[0])
		{
			if (strcmp(args[0], "env") == 0)
			{
				print_env(), free(args), satty == 1 ? write(1, "$ ", 2) : 0;
				continue;
			}
			executeCommand(args, count, bufferEntry, argv);
		}
		free(args), satty == 1 ? write(1, "$ ", 2) : 0;
	}
	free(bufferEntry);
	return (status);
}
