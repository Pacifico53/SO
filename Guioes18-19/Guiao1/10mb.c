#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE_TO_WRITE 10*1024*1024
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){
    int fd, i = 0;
    char buf[BUFFER_SIZE];

    for (i = 0; i < BUFFER_SIZE; i++) {
        buf[i] = 'Y';
    }

    fd = open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
    for (i = 0; i < SIZE_TO_WRITE/BUFFER_SIZE; i++) {
       write(fd, buf, BUFFER_SIZE); 
    }

    return 0;
}
