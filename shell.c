#include "main.h"
/**
 * main - main function
 *
 * Return: ouput
 */
int main(void)
{
	char *command = NULL, **argv, *command_temp = NULL, *p = NULL;
	size_t size = 0, i = 0, interative_mode = isatty(STDIN_FILENO);
	ssize_t n_chars_read;

	while (1)
	{
		if (interative_mode)
		{
			printf("$ ");
			fflush(stdout);
		}
		n_chars_read = getline(&command, &size, stdin);
		
		if (strcmp(command, "exit\n") == 0)
		{
			free(command);
			exit(0);
		}
		if (n_chars_read == -1)
		{
			free(command);
			exit(0);
		}
		command[n_chars_read - 1] = '\0';
		if (empty_line(command) == 0)
			continue;
		command_temp = strdup(command);
		argv = strtok_str(command_temp);
		if (argv && argv[0] == NULL)
		{
			free(command_temp), free(argv[0]), free(argv);
			continue;
		}
		p = getenv_str("PATH");
		which_str(p, argv);
		execve_str(argv);
		free(command_temp);
		for (i = 0; argv[i]; i++)
		{
			free(argv[i]);
		}
		free(argv);
	}
	return (0);
}
