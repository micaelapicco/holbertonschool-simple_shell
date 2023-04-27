#include "main.h"
/**
* execve_str -  execute
* @args: args getline
* Return: nothing
*/
void execve_str(char *path, char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("Error");
		return;
	}
	else if (child == 0)
		execve(path, args, environ);
	else
		wait(NULL);
	return;
}
