#include <sys/ptrace.h>
#include<stdio.h>

int main()
{
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    while(1) printf("hello\n");
}
