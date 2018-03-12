#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t readln(int fildes, void *buf, size_t nbyte);
 
int main(int argc, const char *argv[])
{
    int i=0;
    ssize_t n;
    char buff[1000];
    while(1){
        i++;
        n = readln(0, buff, 1000);
        printf("%d %s\n", i, buff);
    }
    return 0;
}

ssize_t readln(int fildes, void *buf, size_t nbyte){
    int i;
    char *buffer = buf;
    for (int i = 0; i < nbyte-1 && read(fildes, buf, 1) > 0 && buffer[i] != '\n'; i++)
    return i;
}
