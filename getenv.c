#include "main.h"

extern char **environ;

char *getenv_str(char *str)
{
	char *buffer = NULL;
	int len, i = 0;

	len = strlen(str);    
	if (environ)
	{
		for (; environ[i]; i++)
	{
		if (strncmp(environ[i], str, len) == 0 && environ[i][len] == '=')
		{ 
			buffer = environ[i] + len + 1;
			return (buffer);
		}
	}
	}
return (NULL);
}