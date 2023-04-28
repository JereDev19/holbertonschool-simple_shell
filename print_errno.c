#include "shell.h"

void
printErr(int count, char *name, char *bufferEntry)
{
	fprintf(stderr, "%s: %d: %s: not found\n", name, count, bufferEntry);
}