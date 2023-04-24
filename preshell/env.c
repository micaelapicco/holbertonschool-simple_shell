#include <stdio.h>

int main(int argc, char const *argv[], char **ep)
{
    int i = 0;

    while (ep[i])
        puts(ep[i++]);

    return 0;
}
