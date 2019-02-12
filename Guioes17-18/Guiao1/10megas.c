#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEZMEGA 1024*1024*10

int main(int arg, const char *argv[])
{
    char c = 'a';
    int n, f; 
    f = open(argv[1], O_WRONLY | O_CREAT);
    for (n = 0; n < DEZMEGA; n++) {
        write(f, &c, 1);
    }
    return 0;
}
