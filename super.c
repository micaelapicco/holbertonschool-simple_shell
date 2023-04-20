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
    char *args[] = {NULL};

    while (1)
    {
        printf("$ ");
        if ((nread = getline(&buffer, &bufsize, stdin)) == -1)
        {
            break;
        }
        buffer[nread-1] = '\0';

        buf = strtok(buffer, " ");

        if (fork() == 0)
        {
            args[0] = buf;
            if (execvp(buf, args) == -1)
            {
                sprintf(path, "/bin/%s", buf);
            }
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
