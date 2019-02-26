#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>

ssize_t readln(int fildes, void*buf, size_t nbyte){
    ssize_t size = 0;
    char c;
    char* buff = (char*)buf;
    
    while (size < nbyte && read(fildes, &c, 1) == 1) {
        buff[size++] = c;
        if (c == '\0' || c == '\n')
            return size;
    }

    return size;
}

int main(int argc, char *argv[])
{
    int size = atoi(argv[1]);
    char buf[size];
    ssize_t res;

    while ((res = readln(0, buf, size)) != 0){
        write(1, buf, res);
    }
    return 0;
}
