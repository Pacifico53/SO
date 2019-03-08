#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    pid_t pid = 0;
    int i = 0, status;
    for (i = 0; i < 10; i++) {
        if (pid != 0) {
            wait(&status);
            _exit(0);
        }
        else {
            if((pid = fork()) == 0)
                printf("Sou o pid = %d, criado a partir do pid = %d. i = %d.\n", getpid(), getppid(), i);
        }
    }

    return 0;
}
