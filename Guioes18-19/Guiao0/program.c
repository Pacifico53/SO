#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "person.h"

void printHelp(){
    printf("Usage:\n\t-a [name] [age]\t\t\tAdd person.\n");
    printf("\t-u [name] [new age]\t\tUpdate persons age\n");
}

int main(int argc, char *argv[])
{
    if (argc < 2 || strcmp(argv[1], "-h")==0) {
        printHelp();
        return 1;
    }

    int fd = open("db.txt", O_RDWR | O_APPEND);

    if (argc == 4 && strcmp(argv[1], "-a") == 0) {
        Person p = new_person(argv[2], atoi(argv[3]));
        printf("Name: %s.\nAge: %d.\n", p.name, p.age);

        char buf[256];
        char ageStr[10];

        sprintf(ageStr, "%d", p.age);
        strcat(buf, p.name);
        strcat(buf, " ");
        strcat(buf, ageStr);
        strcat(buf, "\n");

        write(fd, buf, strlen(buf));
        printf("Write to db done\n");
    }

    close(fd);
    return 0;
}

