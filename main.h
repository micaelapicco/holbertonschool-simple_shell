#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define DELIM " \n\t=:"

int count_str(char *str);
char **strtok_str(char *str);
int main();

#endif
