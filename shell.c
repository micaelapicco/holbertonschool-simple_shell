#include "main.h"
/**
 * main - main function, determinate if input is interative mode
 * or non interactive and execute if exist command
 * Return: command executed or mesagge error if fail input
 */
int main(void)
{
	char *command = NULL, **argv, *command_temp = NULL, *p = NULL;
	size_t size = 0, interative_mode = isatty(STDIN_FILENO);
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
		command_temp = strdup(command);
		argv = strtok_str(command_temp);
		if (argv && argv[0] == NULL)
		{
			free(command_temp), free(argv[0]), free(argv);
			continue;
		}
		p = getenv_str("PATH");
		if (which_str(p, argv) == 0)
			dprintf(STDERR_FILENO, "./hsh: 1: %s: not found\n", argv[0]);
		execve_str(argv);
		free_array(argv), free(command_temp);
	}
	return (0);
}
