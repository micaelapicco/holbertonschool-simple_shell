#include <stdio.h>

extern char **environ;

int main(int argc, char *argv[], char *env[]) {
    printf("La dirección de env es: %p\n", (void*)env);
    printf("La dirección de environ es: %p\n", (void*)environ);

    return 0;
}