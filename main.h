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

#define DELIM " \n\t=:"

int count_str(char *str);
char **strtok_str(char *str);
int main(void);
void execve_str(char *p, char **args);
char *which_str(char *p, char **argv);
char *getenv_str(char *str);

#endif
