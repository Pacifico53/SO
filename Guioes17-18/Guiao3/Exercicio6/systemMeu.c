#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    execlp("cacafire", "cacafire", NULL);
    return 0;
}
