#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = 0;
    if ((pid = fork()) == 0) {
        execlp("ls", "ls", "-l", NULL); //Isto é executado pelo filho
    }
    
    printf("Isto vai ser executado pelo pai\n");
    return 0;
}

