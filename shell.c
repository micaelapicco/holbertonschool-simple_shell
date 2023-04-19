#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	char *buffer, *copy_buffer, *token, **array;
	int count = 0, i;
	size_t size = 1024;

	while (1)
	{
		buffer = malloc(sizeof(size));
		if (!buffer)
			return (-1);
		printf("$ ");
		getline(&buffer, &size, stdin);
	}
	copy_buffer = strdup(buffer);
	token = strtok(copy_buffer, " ");
		
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
}
