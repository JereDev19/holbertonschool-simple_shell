#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *ar[])
{
	(void)argc, (void)ar;
	size_t result = 0;
	ssize_t chars_read;
	char *output;

	while (1)
	{
		(isatty(STDOUT_FILENO) == 1 ? (write(1, "$ ", 2)) : 0);
		chars_read = getline(&output, &result, stdin);
		if (!chars_read)
		{
			free(output);
			return (-1);
		}
		else if (chars_read == -1)
		{
			free(output);
			return (-1);
		}
			printf("%s", output);
	}
	free(output);
	return (0);
}
int _strtok(int argc, char *argv[])
{
	char *token = NULL;
	int i = 0;

	for (; i < argc, i++)
	{
		token = strtok(argv[i][0], ",! ");
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, ",! ");
		}
	}
}
