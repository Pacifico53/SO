#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int i = 0;
    int status;
    for (i = 0; i < 10; i++) {
        if ((pid = fork()) == 0) {
            printf("Sou um filho (pid = %d), o meu pai é %d. i = %d\n", getpid(), getppid(), i);
            _exit(i);
        }
        else {
            wait(&status);
            printf("Sou o pai, o meu filho (pid = %d) morreu. Codigo de saida = %d\n", pid,  WEXITSTATUS(status));
        }
    }
    return 0;
}
