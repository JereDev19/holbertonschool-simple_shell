#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>

extern char **environ;

int main(void);
void print_env(void);
void print_env_environ(int, char **, char **);
char *_getenv(char *name);
char *find_path(char *str, char *input);
char **tokenize_buffer(char *buffer);

#endif
