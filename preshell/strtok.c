#include "main.h"
/*
 * command_line - function that splits a string and returns an array of each word of the string.
 * Return: strings
 */
int token(char)
{
	char *buffer, *token, *copy;
	size_t size = 0;
	int count = 0, i;
	char **array;

	buffer = malloc(sizeof(size));
	if(!buffer)
		return(-1);
	
	getline(&buffer, &size, stdin);

	copy = strdup(buffer);

	token = strtok(copy, " ");

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
	}

	token = strtok(buffer, " ");

	array = malloc(sizeof(char *) * count);
	for(i = 0; i < count; i++)
	{
		array[i] = strdup(token);
		printf("%s\n", array[i]);
		token = strtok(NULL, " ");
	}
	return (array);
}
