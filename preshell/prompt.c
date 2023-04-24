#include "main.h"
/*
 * main - print prompt
 * @ac: number of item in
 * @av: av: array of strings
 * Return: 0
 */
int main(int ac, char **av)
{
	(void)av;
	(void)ac;

	size_t n_bytes = 0;
	ssize_t n_chars_read;
	char *prompt = "$ ", *buffer = NULL;

	while (1)
	{
	buffer = malloc(sizeof(1024));
	if (!buffer)
		return (-1);

	printf("%s", prompt);
	n_chars_read = getline(&buffer, &n_bytes, stdin);
		if (n_chars_read == -1)
		{
			printf("end-of-file\n");
			return (-1);
		}
	printf("%s", buffer);
	free(buffer);
	}
	return (0);
}
