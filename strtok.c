#include "main.h"
/**
* strtok_str - strings tokenized
* @str: string
* Return: array of strings
*/
char **strtok_str(char *str)
{
	char *token, *copy;
	size_t size, i = 0;
	char **array;

	size = count_str(str);
	copy = strdup(str);
	array = malloc(sizeof(char *) * (size + 1));

	if (!array)
		return(NULL);

	token = strtok(copy, " \t");
	for (i = 0; i < size; i++)
	{
		array[i] = strdup(token);
		token = strtok(NULL, " \t");
	}
	array[i] = NULL;
	free(copy);
	return (array);
}