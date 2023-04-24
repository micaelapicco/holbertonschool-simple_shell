#include "main.h"
/*
 * main - read arguments
 * @av: array
 * @ac: number arg
 * Return: print all arguments
 */
int main(int ac, char **av)
{
	(void)ac;
	int i = 1;

	while (av[i])
	{
		printf("%s ", av[i]);
		i++;
	}
	printf("\n");
	return (0);
}
