#include <stdio.h>
#include <stdlib.h>

int main() {
char *path = getenv("PATH");

if (!path)
    {
        printf("Error\n");
        return (1);
    }
    while (*path)
    {
        if (*path == ':')
	{
            printf("\n");
        }
	else
	{
            printf("%c", *path);
        }
        path++;
    }
return (0);
}
