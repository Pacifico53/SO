#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* Read characters from the pipe and echo them to stdout. */

void read_from_pipe (int file){
    FILE *stream;
    int c;
    stream = fdopen (file, "r");
    while ((c = fgetc (stream)) != EOF)
        putchar (c);
    fclose (stream);
}

void write_to_pipe (int file){
    FILE *stream;
    stream = fdopen (file, "w");
    fprintf (stream, "Hello, world!\n");
    fprintf (stream, "Goodbye, world!\n");
    fclose (stream);
}

int main (void)
{
    pid_t pid;
    int mypipe[2];

    /* Create the pipe. */
    if (pipe (mypipe)){
        fprintf (stderr, "Pipe failed.\n");
        return EXIT_FAILURE;
    }
    else {
        printf("pipe0 = %d\npipe1 = %d\n", mypipe[0], mypipe[1]);
    }

    /* Create the child process. */
    if ((pid = fork ()) == (pid_t) 0){
        /* This is the child process.
            Close other end first. */
        close (mypipe[1]);
        read_from_pipe (mypipe[0]);
        return EXIT_SUCCESS;
    }
    else if (pid < (pid_t) 0){
      /* The fork failed. */
        fprintf (stderr, "Fork failed.\n");
        return EXIT_FAILURE;
    }
    else{
        /* This is the parent process.
            Close other end first. */
        close (mypipe[0]);
        write_to_pipe (mypipe[1]);
        return EXIT_SUCCESS;
    }
}

