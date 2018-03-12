#include <unistd.h>   /* chamadas ao sistema: defs e decls essenciais*/
#include <fcntl.h>    /*O_RDONLY, O_WRONLY, O_CREAT, O_* */
#include <stdio.h>

int main()
{
    char c;
    while (read(0, &c, 1) > 0) {
        write(1, &c, 1);
    }
    return 0;
}
