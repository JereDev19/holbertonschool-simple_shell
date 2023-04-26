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
	char *command = NULL, *bufferEntry = NULL, **args = NULL;
	int status = 0, satty = isatty(STDOUT_FILENO), count = 0;
	struct stat buffer;

	satty == 1 ? write(1, "$ ", 2) : 0;
	while (getline(&bufferEntry, &sizeBuffer, stdin) >= 0)
	{
		count += 1;
		if (strlen(bufferEntry) == 1)
		{
			satty == 1 ? write(1, "$ ", 2) : 0;
			continue;
		}
		else if (strstr(bufferEntry, "exit"))
		{
			if (bufferEntry)
				free(bufferEntry);
			exit(status);
		}
		if (strcmp(bufferEntry, "env\n") == 0)
			print_env();
		args = generate_args(bufferEntry);
		if (args && args[0])
		{
			/*If is rute absolute, ejecute this, if is only command, goes to the other*/
			if (stat(args[0], &buffer) == 0)
			{
				stat(args[0], &buffer) == 0 && S_ISREG(buffer.st_mode) && (buffer.st_mode & S_IXUSR) ? (command = args[0], status = forkProcess(command, args)) : (printErr(count, argv[0], bufferEntry), status = 126);
			}
			else if (stat(args[0], &buffer) == -1)
			{
				command = get_path(args[0]);
				if (command)
				{
					status = forkProcess(command, args), free(command);
					(status == -1) ? status = 2 : 0; /* si forkProcess falla, status es 2 */
				}
				else
					printErr(count, argv[0], bufferEntry), status = 127;
			}
		}
		free(args), satty == 1 ? write(1, "$ ", 2) : 0;
	}
	free(bufferEntry);
	return (status);
}
