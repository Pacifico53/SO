#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int i;
    for (i = 0; i < argc; i++) {
        printf("Argumento %d => %s\n", i, argv[i]);
    }
    return 0;
}
