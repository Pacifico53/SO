#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    int i, status = 0;
    for (i = 1; i<argc; i++) {
        if ((pid=fork()) == 0) {
            execlp(argv[i], argv[i], NULL);
        }
        else{
            wait(&status);
        }
    }
    
    return 0;
}

