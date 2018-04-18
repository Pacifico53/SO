#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int seconds = 0;
int count = 0;

void timer(int signum){
    printf("\nSegundos: %d\n", seconds); //Quando recebe um SIGINT (ctrl-c) da print dos segundos
    count++; // incrementa a count dos ctrl-c
}

void countTime(int signum){
    seconds++;   // conta os segundos
    alarm(1);    //este alarm aqui faz basicamente um loop, para ir contando os segundos
}

void countCtrlC(int signum){
    printf("\nNumero de vezes Ctrl-C foi carregado: %d\n", count);
    exit(1);
}

int main(int argc, char *argv[])
{
    signal(SIGINT, timer); // a espera de receber Ctrl-C
    signal(SIGALRM, countTime); // a contar o tempo (esperando pelo sinal alarm a cada segundo)
    signal(SIGQUIT, countCtrlC); // a espera de receber Ctrl-\

    alarm(1); //Inicia a contagem, passado 1 segundo manda um SIGALRM
    while(1){
        pause();  // para o programa estar a fazer alguma coisa, enquanto espera pelos sinais
    }
    return 0;
}
