#include "main.h"
/*
* strtok -  strings tokenized
* @str: string
* Return: array of strings
*/
char **strtok(char *str)
{
    char *token, *copy;
	size_t size;
	char **array;

    size = count(str);
	array = malloc(sizeof(size));
	if(str)
		return(-1);

	copy = strdup(str);

	token = strtok(copy, " ");

	count(token, 
}

}