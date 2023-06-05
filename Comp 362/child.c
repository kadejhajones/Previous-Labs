#include	<stdio.h>
#include	<unistd.h>
#include    <errno.h>
#include    <sys/types.h>
#include    <sys/wait.h>

int main(int argc, char *argv[])
{
   printf("Process %s pid is: %d\n", argv[1], getpid());

   int i = 0;
   while (i == 0) /* NOTE: this is an endless loop; use gdb to change the value of i and continue */
      ;

   printf("Process %s is terminating\n", argv[1]);
}
