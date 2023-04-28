#include "main.h"
/**
 * empty_line - checks if the line is empty
 * @input: input to check
 * Return: 0 if empty
*/
int empty_line(char *input)
{
    if (strcmp(input, "\n") == 0)
        return (0);
    
    return (1);
}