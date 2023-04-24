#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

int main()
{
	char *command = NULL, **argv;
	size_t size = 0;
	pid_t child;
	ssize_t n_chars_read;
	int status;

	while (printf("$ ")) 
	{
		n_chars_read = getline(&command, &size, stdin);
		if (n_chars_read == -1)
		{
			printf("Exit...\n");
			free(command);
			exit(0);
		}
		if (!command)
			return (-1);
		argv = strtok_str(command);

	child = fork ();
	if (child == 0)
	{	
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error");
			exit(0);
		}
	}
	if (child == -1)
	{	perror("Error");
		exit(1);
	}
	else
		wait(&status);		
	}
	free(command);
	free(argv);
	return(0);
}