#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    char buf[size];
    ssize_t res;

    while ((res = read(0, buf, size)) != 0){
        write(1, buf, res);
    }
    return 0;
}
