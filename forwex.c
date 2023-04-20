#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
/**
 * main - executes the command ls -l /tmp in 5 different child processes.
 * Return. 0 .
 **/ 
int main()
{
int i =  0;

for(; i < 5; i++)
{
if(fork() == 0)
		{
		execl("/bin/ls", "ls", "-l", "/tmp", NULL);
		return(0);
		}
	wait(NULL);
}
return(0);
}
