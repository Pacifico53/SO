#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main()
{
    int* status;
    if(fork()==0){
        execlp("ls", "ls", "-l", NULL);
        perror("Erro no execlp\n");
        _exit(-1);
    }else wait(status);
}
