#include "main.h"
/*
* strtok -  strings tokenized
* @str: string
* Return: array of strings
*/
int execve_str(char **args)
{
    pid_t child = fork();

    if (child == -1)
    {
        perror("Error");
        return (1);
    }
    else if (child == 0)
        execve(args[0], args, NULL);
    else
        wait(NULL);
    return (0);
}