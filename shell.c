#include "main.h"
/**
 * main - main function
 *
 * Return: ouput
 */
int main(void)
{
	char *command = NULL, **argv, *command_temp = NULL, *p = NULL;
	size_t size = 0, i = 0;
	ssize_t n_chars_read;
	int interative_mode = isatty(STDIN_FILENO);

	while (1)
	{
		if (interative_mode)
		{	
			printf("$ ");
			fflush(stdout);
		}
		n_chars_read = getline(&command, &size, stdin);

		if (n_chars_read == -1)
		{
			free(command);
			printf("\n");
			exit(0);
		}
		/* verificar si hay una linea vacia */
		command[n_chars_read -1] = '\0';

		command_temp = strdup(command);
		argv = strtok_str(command_temp);

		p = getenv_str("PATH");

		which_str(p, argv);
		/* NO llamar a esta funcion si no se encontro el comando (ejemplos: slkf, /usr/bsad)*/
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
