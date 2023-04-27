#include "main.h"
/**
 * main - main function
 *
 * Return: ouput
 */
int main(void)
{
	char *command = NULL, **argv, *command_temp = NULL, *p = NULL, *full_path = NULL;
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
		command_temp = strdup(command);
		printf("comand_temp: %s\n", command_temp);
		argv = strtok_str(command_temp);

		p = getenv_str("PATH");
		printf("path: %s\n", p);

		full_path = which_str(p, argv);
		printf("full_path: %s\n", full_path);
		execve_str(full_path, argv);

	}
	return (0);
}
