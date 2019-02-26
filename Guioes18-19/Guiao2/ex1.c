#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    printf("Bom dia eu sou o %d. O meu pai chama se %d... Já é velhinho.\n", getpid(), getppid());
    sleep(30);
    return 0;
}
