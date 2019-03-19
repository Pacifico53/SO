#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int fd1, fd2, fd3;
    fd1 = open("/etc/passwd", O_RDONLY);
    fd2 = open("saida.txt", O_WRONLY);
    fd3 = open("erro.txt", O_WRONLY);

    dup2(fd1, 0);        //O input agora é o file /etc/passwd
    dup2(fd2, 1);        //O outpur agora é o file saida.txt
    dup2(fd3, 2);        //O error agora é o error.txt
    
    int status=0;
    char buf[53];
    int pid;
    
    if ((pid=fork()) == 0) {
        read(0, buf, 53);    //lê 53 bytes do input (passwd)
        write(1, buf, 53);   //escreve os 53 bytes lidos no output (saida.txt)
        perror("ola");       //manda um erro para error.txt
    }
    else{
        wait(&status);
    }
    
    return 0;
}
