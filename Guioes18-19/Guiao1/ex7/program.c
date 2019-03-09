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

int findPerson(int fd, char* name, char* age){
    int totalSize = strlen(name) + strlen(age);
    char buf[1], aux[52];
    int flag = 0;
    int rd;
    while (!flag && (rd = read(fd, buf, 8))) {
        printf("buf = %s\n",buf);
        if (strcmp(buf, "\n")!=0) {
            strcat(aux,buf);
            printf("aux = %s\n", aux);
        }
        else if(strcmp(aux, name)==0){
            flag = 1;
        } else{strcpy(aux, "");}
    }
    return flag;
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
    else if (argc == 4 && strcmp(argv[1], "-u") == 0) {
        int f = findPerson(fd, argv[2], argv[3]);
        if (f) {
            printf("yay?\n"); 
        }
    }

    close(fd);
    return 0;
}

