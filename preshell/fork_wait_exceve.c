#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	pid_t father_pid;
    pid_t child_pid;
	int status, counter = 0;

	while (counter < 5 && child_pid)
	{
		child_pid = fork();
		if (child_pid == -1)
		{perror("Error");
			return (1); }
		wait(&status);
		counter++;
	}
	father_pid = getppid();
	if (child_pid == 0)
		printf("%u\n", child_pid);
	if (child_pid > 0)
		printf("%u\n", father_pid);

	execve(argv[0], argv, NULL);
}

