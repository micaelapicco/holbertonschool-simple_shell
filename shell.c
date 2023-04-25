#include "main.h"
/**
 * main - main function
 *
 * Return: ouput
 */
int main(void)
{
	char *command = NULL, **argv;
	size_t size = 0;
	ssize_t n_chars_read;

	while (1)
	{
		printf("$ ");
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
		if (getenv_str(command) == NULL)
			perror("Error getenv");

	}
	free(command);
	free(argv);
	printf("\n");
	return (0);
}
