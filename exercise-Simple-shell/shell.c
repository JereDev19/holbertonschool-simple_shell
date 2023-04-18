#include "shell.h"

int main(void)
{
	ssize_t chars_read = 0;
	size_t sizeBuffer = 0;
	char *bufferEntry = NULL;

	bufferEntry = malloc(sizeof(char *) * sizeBuffer);
	if (!bufferEntry)
		return (1);

	while (1)
	{
		(isatty(STDOUT_FILENO) == 1 ? write(1, "$ ", 2) : 0);
		chars_read = getline(&bufferEntry, &sizeBuffer, stdin);
		if (!chars_read)
		{
			free(bufferEntry);
			return (1);
		}
		else if (chars_read == -1)
		{
			free(bufferEntry);
			printf("Existing for the shell\n");
			return (0);
		}
	}
}
