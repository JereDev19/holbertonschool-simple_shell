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

/*Variable that it have all enviroment variables*/
extern char **environ;

/* Function to generate arguments */
char **generate_args(char *);

/* Function to print env. */
void print_env(void);

/* Get a give enviroment variable */
char *_getenv(const char *);

/* Function to work with PATH*/
char *get_path(char *);

/* Function to print command not founded*/
void printErr(int, char *, char *);

/*To create child proccess and get status of it*/
int forkProcess(char *, char **);

/*Free a double pointer*/
void free_array(char **);

/*Search a path and if it not found, search path1*/
char *find_command_path(char *, char *);

#endif
