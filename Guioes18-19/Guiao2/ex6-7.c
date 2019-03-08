#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <fcntl.h>

int searchLine(int mat[], int col, int num){
    int r = 0, i = 0;
    for (i = 0; i < col && r == 0; i++) {
        if(mat[i] == num){
            r = 1;
        }
    }
    return r;
}

int main()
{
    srand(time(NULL)); //SEED RANDOMNESS

    int col = (rand() % 500) + 100;
    printf("col = %d\n", col);
    int lin = (rand() % 50) + 5;
    printf("lin = %d\n", lin);

    int i = 0, j = 0;
    int mat[lin][col];
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            mat[i][j] = rand() % 3000;
        }
    }
    
    int num = rand() % 3000;

    printf("Random matrix done, columns = %d, lines = %d\nNumber to find = %d\n", col, lin, num);

    
    pid_t pid = 1;
    int aLine = 0;
    int flag = 0;
    int status;

    for (i = 0; i < lin; i++) {
        if (pid != 0) {
            pid = fork();
            aLine = i;
        }
        else{
            break;
        }
    }

    if (pid == 0) {
        flag = searchLine(mat[aLine], col, num);
        if (flag == 1) {
            printf("Eu pid = %d encontrei na linha %d.\n", getpid(), aLine); 
            _exit(0);
        }
        else {
            printf("Eu pid = %d nao encontrei na linha %d.\n", getpid(), aLine);
            _exit(1);
        }
    }
    else {
        for (i = 0; i < lin; i++) {
            wait(&status);
            if(status == 0){
                printf("Found num!\n");
            }
        }
    }
    return 0;
}

