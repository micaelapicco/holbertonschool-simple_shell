#include "main.h"
/*
 * command_line - function that splits a string and returns an array of each word of the string.
 * Return: strings
 */
int main(void)
{
	char *buffer, *token, *copy;
	size_t size = 0;
	int count = 0;

	buffer = malloc(sizeof(size));
	if(!buffer)
		return(-1);
	
	getline(&buffer, &size, stdin);

	copy = strcpy(copy, buffer);

	token = strtok(copy, " ");
	count++;

	while (token != NULL)
	{
		token = strtok(NULL, " ");
		count++;
	}
	token = strtok(buffer, " ");
	printf("%s\n", token);

	while(count > 1)
	{
		token = strtok(NULL, " ");
		printf("%s\n", token);
		count--;
	}
	return (0);
}
