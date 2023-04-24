#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define DELIM " \n\t=:"

int count_str(char *str);
char **strtok_str(char *str);
int main(void);
int execve_str(char **args);

#endif
