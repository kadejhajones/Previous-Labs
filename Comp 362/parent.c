#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

int main() {
    pid_t pid;

    // fork a child process
    pid = fork();

    if (pid < 0) // error occurred
        exit(EXIT_FAILURE);
   else if (pid == 0) // pid == 0 indicates that it is the child
    {
        printf("I am the child %d\n", getpid());
        if (execlp("./child", "child", "Hello Parent! Please do not kill me!", NULL) < 0)
            exit(EXIT_FAILURE);  // this should never be executed, since the process is morphed by now
    }
    else // pid > 0 ==> so this must be the parent
    {
        printf("I am the parent %d\n", getpid());
        /* parent will wait for the child to complete */
        if (waitpid(-1, NULL, 0) < 0)
            printf("-1 from wait() with errno = %d\n", errno);

        printf("Child terminated; parent exiting\n");
        exit(EXIT_SUCCESS);
    }
}
