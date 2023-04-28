#include "main.h"
/**
* count_str - counter of inputings tokenized
* @input: input
* Return: counter
*/
int count_str(char *input)
{
	int count = 0;
	char *copy, *token;

	copy = strdup(input);
	token = strtok(copy, " \t");
	for (count = 0; token; count++)
	{
		token = strtok(NULL, " \t");
	}
	free(copy);
	return (count);
}
