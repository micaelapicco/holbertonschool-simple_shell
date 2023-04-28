#include "main.h"
/**
 * which_str - Checks if the input is a path. If not, tokenizes PATH
 * variable and generate differentes paths
 * @path: path
 * @argv: arguments
 * Return: full path
 */
char *which_str(char *path, char **argv)
{
    char *copy = NULL, *token = NULL, *full_path = NULL;

	if ((access(argv[0], F_OK) == 0))
		return(argv[0]);

    copy = strdup(path);
    token = strtok(copy, ":");

    full_path = malloc(sizeof(char) * (strlen(path) + strlen(argv[0])) + 2);

	if (!full_path)
		{
			free(full_path);
			free(copy);
			return (0);
		}
	
    while (token)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		if (access(full_path, F_OK) == 0)
		{
			free(argv[0]);
			argv[0] = full_path;
			free(copy);
			return (full_path);
		}

		token = NULL;
		token = strtok(NULL, ":");
	}
	return (0);

}