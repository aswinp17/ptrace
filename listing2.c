/* `tracer' parent */
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
        execl("/home/aswin/Desktop/linux/ptrace/child1", "child1", NULL);
        printf("exec failed...\n");
    } else {
        sleep(1);
        kill(pid, SIGINT);
        wait(&status); // wait for child to stop
        if(WIFSTOPPED(status))
            printf("child has stopped...\n");
        sleep(3);
        ptrace(PTRACE_CONT, pid, 0, 0);
        /* Will not come out of this wait because
         * child does not terminate.
         */
        wait(&status); 
    }
}
        

