#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    execv("ex3", argv);
    return 0;
}

