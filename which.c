#include "main.h"
/**
 * which_str - Checks if the input is a path. If not, tokenizes PATH
 * variable and generate differentes paths
 * @p: path
 * @argv: arguments
 * Return: full path
 */
char *which_str(char *p, char **argv)
{
    char *copy = NULL, *token = NULL, *full_path = NULL;

    copy = strdup(p);
    token = strtok(copy, ":");
    
    while (token)
	{
		full_path = malloc(sizeof(strlen(token) + sizeof(strlen(argv[0])+ 2)));
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		if (full_path == 0)
		{
			free(copy);
			return (full_path);
		}
		free(full_path);
		token = NULL;
		token = strtok(NULL, ":");
	}
	free(copy);
	return (0);

}