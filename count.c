#include "main.h"
/**
* count_str - counter of strings tokenized
* @str: string
* Return: counter
*/
int count_str(char *str)
{
	int count = 0;
	char *copy, *token;

	copy = strdup(str);
	token = strtok(copy, DELIM);
	for (count = 0; token; count++)
	{
	token = strtok(NULL, DELIM);
	}
	free(copy);
	free(token);
	return (count);
}
