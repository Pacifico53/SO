#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fd1, fd2, fd3;
    fd1 = open("/etc/passwd", O_RDONLY);
    fd2 = open("saida.txt", O_WRONLY);
    fd3 = open("erro.txt", O_WRONLY);

    dup2(fd1, 0);        //O input agora é o file /etc/passwd
    dup2(fd2, 1);        //O outpur agora é o file saida.txt
    dup2(fd3, 2);        //O error agora é o error.txt
    
    char buf[53];
    read(0, buf, 53);    //lê 53 bytes do input (passwd)
    write(1, buf, 53);   //escreve os 53 bytes lidos no output (saida.txt)
    perror("ola\n");       //manda um erro para error.txt

    execlp("wc", "wc", NULL);
    
    return 0;
}
