#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i;
    if (argc<2) {
        printf("Escreve pelo menos um argumento.\n");
        return 1;
    }
    for (i = 1; i < argc; i++) {
        printf("argv[%d] = %s\n",i, argv[i]);   
    }
    return 0;
}

