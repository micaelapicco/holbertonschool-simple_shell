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

    copy = strdup(path);
    token = strtok(copy, DELIM);

	if ((access(argv[0], F_OK) == 0))
		return(argv[0]);

    full_path = malloc(sizeof(char) * (strlen(path) + strlen(argv[0])) + 2);

	if (!full_path)
		{
			free(copy);
			free(token);
			free(full_path);
			return (0);
		}
	printf("token: %s", token);
    while (token)
	{
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, argv[0]);
		printf("full path: %s", full_path);
		if (access(full_path, F_OK) == 0)
		{
			free(copy);
			free(token);
			return (full_path);
		}

		token = NULL;
		token = strtok(NULL, ":");
	}
	return (0);

}