#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX_CHILD 128

int count;
int child_num;
int isAlive;
int childID[MAX_CHILD];

void startChilds(int max){
    count = 0;
    isAlive = child_num = max;

    if (max > 0) {
        kill(childID[0], SIGCONT);
        alarm(1);
    }
}

void nextChild(){
    kill(childID[count], SIGSTOP);
    
    if (++count == child_num) {
        count = 0;
    }

    kill(childID[count], SIGCONT);
    alarm(1);
}

void killChild(){
    if (waitpid(-1, NULL, WNOHANG)) {
        isAlive--;
        nextChild();
    }
}

int main(int argc, char *argv[])
{
    int i, id;

    signal(SIGALRM, nextChild);
    signal(SIGCHLD, killChild);
    
    for (i = 0; i < argc; i++) {
        id = fork();

        if (id) {
            childID[i-1] = id;
        }else{
            kill(getpid(), SIGSTOP);
            execlp(argv[i], argv[i], NULL);
            _exit(1);
        }
    }

    startChilds(argc - 1);

    while (isAlive) {
        pause();
    }

    return 0;
}
