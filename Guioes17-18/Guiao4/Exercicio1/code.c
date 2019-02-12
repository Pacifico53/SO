#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc, const char *argv[])
{
    char buf[1024];
    
    int fd;
    fd=open("saida.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
    
    int fi;
    fi = open("/etc/passwd", O_RDONLY);
    
    int fe;
    fe = open("erros.txt", O_CREAT | O_WRONLY | O_TRUNC, 0666);
     
    if (fe == -1) {
        perror("Erro ao abrir o ficheiro erros.txt");
        _exit(-1);
    }

    dup2(fe, 2);
    close(fe);

    perror("Teste!\n");
    
    if (fd == -1) {
        perror("Erro ao abrir o ficheiro output.txt");
        _exit(-1);
    }
    if (fi == -1) {
        perror("Erro ao abrir o ficheiro passwd");
        _exit(-1);
    }

    dup2(fd, 1);
    close(fd);

    dup2(fi, 0);
    close(fi);

    read(0, buf, 1024);
    printf("%s\n", buf);
    return 0;
}
