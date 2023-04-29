#include "main.h"
/**
* execve_str -  execute
* @argv: args getline
* Return: nothing
*/
int execve_str(char **argv)
{
	pid_t child = fork();

	if (child == -1)
	{
		fprintf(stderr, "./hsh: 1: %s: not found", argv[0]);
		exit(127);
	}
	else if (child == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	else
		wait(NULL);
	return (0);
}
