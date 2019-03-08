#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    pid_t pid = 1;
    int i = 0, status;
    for (i = 0; i < 10; i++) {
        if (pid != 0) {
            pid = fork();
        }
    }
    if (pid == 0) {
        printf("Ola eu sou o filho pid = %d. O pai é pid = %d\n", getpid(), getppid());
        _exit(0);
    }
    else {
        wait(&status);
        printf("Sou o pai = %d. O filho = %d morreu,status = %d.\n", getpid(), pid, status);
    }
    return 0;
}

