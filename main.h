#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>

extern char **environ;

int count_str(char *str);
char **strtok_str(char *str);
int main(void);
int execve_str(char **argv);
char *which_str(char *p, char **argv);
char *getenv_str(char *str);
int empty_line(char *input);

#endif
