#include <stdio.h>
#include <unistd.h>

int main()
{
    execlp("ls", "ls", "-l", NULL);
    printf("Isto nao vai ser executado.\n");
    return 0;
}
