#include "shell.h"

int main(void)
{
	ssize_t chars_read = 0;
	size_t sizeBuffer = 0;
	char *bufferEntry = NULL;
	char *comandPath = NULL;
	int status = 0;

	bufferEntry = malloc(sizeof(char *) * sizeBuffer);
	if (!bufferEntry)
		return (1);

	while (1)
	{
		(isatty(STDOUT_FILENO) == 1 ? write(1, "$ ", 2) : 0);
		chars_read = getline(&bufferEntry, &sizeBuffer, stdin);

		/* -- Verify if the command is exit or the user place exit --*/
		if (chars_read == -1 || strcmp(bufferEntry, "exit\n") == 0)
			((bufferEntry) ? free(bufferEntry), exit(status) : 0);

		else if (strcmp(bufferEntry, "env\n") == 0)
			print_env();

		/*path copy so not modify the original buffer*/
		comandPath = strdup(bufferEntry);

		/**
		 * Pasos generales: (nos vamos a encontrar 30 mil error en el medio)
		 *
		 * Step 1:
		 *  - Hacer funcion que devuelva un array con los parametros dados (en cada indice un determinado parametro o argumento).
		 *
		 * Step 2:
		 *  - Buscar el path de ese argumento que obtuvimos y ejecutar el comando.
		 */
	}
}
