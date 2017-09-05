#include<stdio.h>
#include <sys/ptrace.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



//compile into `child2'

int main()
{
    /* Note that we are not calling ptrace(PTRACE_TRACEME,...)
     * here. That will be done by the process which has
     * exec'd this one.
     */
    printf("child starts...\n");
    sleep(1);
    while(1) printf("hello\n");
}

