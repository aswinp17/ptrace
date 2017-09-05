#include<stdio.h>



/* Compile this program into `child3' */
int main()
{
    printf("child3 starts...\n");
    asm("pushq %rbx\n\t"
        "mov  $143, %rbx\n\t"
        "L1: cmp $245, %rbx\n\t"
        "jne L1\n\t"
        "pop %rbx\n\t");
    printf("child3 outside loop...\n");
}

