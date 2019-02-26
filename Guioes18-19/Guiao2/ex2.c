#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    pid_t pid;
    if ((pid = fork()) == 0) {
        printf("Cumprimentos eu sou o filho do %d e o meu nome é %d.\n", getppid(), getpid());
    }
    else {
        printf("Bom dia eu sou o %d, pai do %d. O meu pai chama se %d... Já é velhinho.\n", getpid(), pid, getppid());
    }
    sleep(30);
    return 0;
}
