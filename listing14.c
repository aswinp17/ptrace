#include <sys/ptrace.h>
#include <signal.h>
#include <unistd.h>
#include <sys/user.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdio.h>
int main()
{
    
    int  status = 0, pid, addr; 
    struct user_regs_struct uregs;

    scanf("%x%d", &addr, &pid);
    ptrace(PTRACE_ATTACH, pid, 0, 0);
    wait(&status);
    ptrace(PTRACE_GETREGS, pid, 0, &uregs);
    printf("eip: %llx\n", uregs.rip);
    uregs.rip = addr;
    ptrace(PTRACE_SETREGS, pid, 0, &uregs);
    ptrace(PTRACE_CONT, pid, 0, 0);
    wait(&status);
    if(WIFEXITED(status))printf("child over\n");
    sleep(1000);
}


