#include "main.h"
/**
* execve_str -  execute
* @args: args getline
* Return: nothing
*/
void execve_str(char **argv)
{
	pid_t child = fork ();

	if (child == -1)
	{
		perror("Error");
		return;
	}
	else if (child == 0)
	{	
		if (execve(argv[0], argv, environ) == -1) /* Checkear error de execve (-1) */
			{
				perror("Error");
				exit(1);
			}
	}
	else
		wait(NULL);
	return;
}
