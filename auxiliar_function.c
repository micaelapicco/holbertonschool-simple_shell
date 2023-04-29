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

/**
 * free_array - free array
 * @array: array of strings
 * Return: Nothing
*/
void free_array(char *array[])
{
	int i = 0, j = 0;

	if (!array)
		return;
	while (array[i])
		i++;

	for (; j < i; j++)
		free(array[j]);

	free(array);
}
