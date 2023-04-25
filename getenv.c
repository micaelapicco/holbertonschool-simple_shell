#include "main.h"

extern char **environ;

char *getenv_str(const char *name)
{
	int name2;
	int i = 0;

	name2 = strlen(name);    

	for (; environ[i] != NULL; i++)
	{
        if (strncmp(environ[i], name, name2) == 0 && environ[i][name2] == '=')
	{
        return (&environ[i][name2+1]);
        }
    }
return (NULL);
}