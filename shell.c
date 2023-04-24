#include "main.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main()
{
	char *command = NULL, **argv;
	size_t size = 0;
	ssize_t n_chars_read;

	while (printf("$ ")) 
	{
		n_chars_read = getline(&command, &size, stdin);
		if (n_chars_read == -1)
		{
			printf("Exit...\n");
			free(command);
			exit(0);
		}
		if (!command)
			return (-1);
		argv = strtok_str(command);

	execve_str(argv);
	}
	free(command);
	free(argv);
	return(0);
}