#include "main.h"
/**
 * main - main function
 *
 * Return: ouput
 */
int main(void)
{
	char *command = NULL, **argv, *command_temp = NULL, *p = NULL, *full_path = NULL;
	size_t size = 0, i = 0;
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
		command[n_chars_read -1] = '\0';
		if (!command)
			return (-1);
		command_temp = strdup(command);
		argv = strtok_str(command_temp);

		p = getenv_str("PATH");

		full_path = which_str(p, argv);
		execve_str(full_path, argv);
		free(command_temp);
		for (i = 0; argv[i]; i++)
		{
			free(argv[i]);
		}
		free(argv);
		free(full_path);
	}
	return (0);
}
