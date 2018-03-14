#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>

//TODO -i e -o serem opcionais

int main(int argc, char *argv[])
{
    if (argc < 5 || strcmp(argv[1], "-i") != 0 || strcmp(argv[3], "-o") != 0) {
       perror("Usage: \"redir [-i ficheiroEntrada] [-o ficheiroSaida] command arg1 ...\"\n");
       _exit(1);
    }
    
    int fi = open(argv[2], O_RDONLY);

    int fo = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);

    if (!fi) {
        perror("Erro a abrir ficheiro de entrada!");
        _exit(-1);
    }

    if (!fo) {
        perror("Erro a abrir ficheiro de saida!");
        _exit(-1);
    }

    dup2(fi, 0);
    close(fi);

    dup2(fo, 1);
    close(fo);
    
    int commandIndex = 5;

    execvp(argv[5], argv + commandIndex);

    return 0;
}
