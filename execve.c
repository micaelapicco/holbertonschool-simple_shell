#include "main.h"
/**
* execve_str -  execute
* @args: args getline
* Return: nothing
*/
void execve_str(char *p, char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("Error");
		return;
	}
	else if (child == 0)
		execve(p, args, NULL);
	else
		wait(NULL);
	return;
}
