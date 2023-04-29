#include "main.h"
/**
 * getenv_str - get environ and save the environ in a buffer
 * @env: environ
 * Return: environ in format string
*/
char *getenv_str(char *env)
{
	char *buffer = NULL;
	int len, i = 0;

	len = strlen(env);
	if (environ)
	{
		for (; environ[i]; i++)
		{
			if (strncmp(environ[i], env, len) == 0 && environ[i][len] == '=')
			{
				buffer = environ[i] + len + 1;
				return (buffer);
			}
		}
	}
return (NULL);
}
