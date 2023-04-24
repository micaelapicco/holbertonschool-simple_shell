#include "main.h"
/*
* strtok_str -  strings tokenized
* @str: string
* Return: array of strings
*/
char **strtok_str(char *str)
{
	char *token, *copy;
	size_t size, i = 1;
	char **array;

	copy = strdup(str);
	size = count_str(str);
	array = malloc(sizeof(char *) * size);

	if (!array)
		return(NULL);

	token = strtok(copy, DELIM);
	for (i = 0; i < size; i++)
	{
		array[i] = strdup(token);
		token = strtok(NULL, DELIM);
	}
	return (array);
}