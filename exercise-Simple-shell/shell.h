#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdarg.h>

extern char **environ;

/* Principal function */
int main(void);

/* Function to work with ENV and ENVIRON*/
void print_env(void);
void print_env_environ(int, char **, char **);
char *_getenv(const char *name);

/* Function to work with PATH*/
void print_path(void);
char *entry_commands(char *);

/*To create proccess*/
int forkProcess(char **);

#endif
