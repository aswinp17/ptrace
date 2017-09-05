#include <sys/ptrace.h>
#include <signal.h>
#include <unistd.h>

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pid, status;
    if((pid = fork()) == 0) {
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        execl("/home/aswin/Desktop/linux/ptrace/child2", "child2", NULL);
        printf("exec failed...\n");
    } else {
        wait(&status);
        if(WIFSTOPPED(status))
            printf("child has stopped...\n");
        sleep(10);
        ptrace(PTRACE_CONT, pid, 0, 0);
        wait(&status);
    }
}
        

