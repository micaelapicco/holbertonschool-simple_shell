#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t nread;
    char *buf;
    char path[100];
    char *args[10];
    int i = 0;

    while (1)
    {
        printf("$ ");
        if ((nread = getline(&buffer, &bufsize, stdin)) == -1)
        {
            break;
        }
        buffer[nread-1] = '\0';

        buf = strtok(buffer, " ");
	
	while (buf != NULL)
	{
	args[i] = buf;
	buf = strtok(NULL, " ");
	i++;
	}

	args[i] = NULL;

        if (fork() == 0)
        {
            	execve(args[0], args, NULL);
		sprintf(path, "/bin/%s", args[0]);
                execve(path, args, NULL);
	    	exit(EXIT_SUCCESS);
        }
        else
        {
            wait(NULL);
        }
    }

    free(buffer);
    return(0);
}
