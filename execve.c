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
		perror("Error");
		return (1);
	}
	else if (child == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else
		wait(NULL);
	return (0);
}
