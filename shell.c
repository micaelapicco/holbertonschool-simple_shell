#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
	char *command = NULL, **argv, *token;
	size_t size = 0, count = 0;
	pid_t child;
	int status;

	while (1) 
	{
		printf("$ ") 
		getline(&command, &size, stdin);
		if (!command)
			return (-1);
		argv = malloc(sizeof(char *) * strlen(command));
		token = strtok(command, "\n ");
		for (count = 0; token; count++)
		{
			argv[count] = strdup(token);
			token = strtok(NULL, "\n ");
		}
	child = fork ();
	if (child == 0)
	{	
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error\n");
	}
	if (child == -1)
	{	perror("Error\n");
		exit(1);
	}
	else
		wait(&status);		
	}
	free(command);
	free(token);
	return(0);
}