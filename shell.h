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

/* Function to generate arguments */
char **generate_args(char *param);

/* Function to work with ENV and ENVIRON*/
void print_env(void);
char *_getenv(const char *name);

/* Function to work with PATH*/
void print_path(void);
char *get_path(char *);

/* Function to print command not founded*/
void printErr(int count, char *name, char *bufferEntry);

/*To create proccess*/
int forkProcess(char *, char **);

#endif
