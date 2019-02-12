#include <stdio.h>
#include <unistd.h> /* chamadas ao sistema: defs e decls essenciais */
#include <sys/wait.h> /* chamadas wait*() e macros relacionadas */


int main()
{
    int max = 2;
    int i;
    int f = fork();
    if (f==0){
         printf("Este é o pid do FILHO: %d\n", getpid());
    }else{
            printf("Este é o pid do PAI: %d, e este é o filho: %d\n", getpid(), f);
         }
    char a = getchar(); //ISTO ESTA AQUI PARA FAZER CTRL-Z ENQUANTO O PROGRAMA EXECUTA PARA ANALISAR OS PIDS POR PS
    return 0;
}

