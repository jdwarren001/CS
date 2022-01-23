# Context Switch

    #include <stdio.h>

    char *stack; // make an array of stacks

    void launchThread(void (*FunPtr)(int x), void *stack) {
        asm("mov %rsi,%rsp"); //rsi is SECOND argument, put in the stack pointer
        FunPtr('a'); //runs loc of function at this location (top of stack)
    }

    void createThread(void (*FunPtr)(int x)) {
        stack=(char *)malloc(64000)+64000;
        launchThread(Funptr, stack);
    }

    void fun(int x) {
        putchar(x);
    }

    int main () {
        createThread(fun);
    }

Use C for this code, will be much easier.

-> gcc -S Simple.c -o Simple.s
 - Creates the assembly code
 - We create the assembly, look for the functions calls in our S call
   - Then, we can see where the memroy is coming from/going 
     - edi -> eax
     - If edi, then esi
       - Calls edi first, store esi to ensure esi is still there
       - Pop that value INTO rdi (Now the esi will be called)


typedef context {
 long rax, rbx, rcx, rdx, rsi, rdi, rsp, rbp, rip
};

void saveRegs(context *p) {
    asm("mov %rax,0(%rdi)");
    asm("mov %rbx,8(%rdi)");
}

void loadRegs(context *p) {
    asm("mov 0(%rdi),%rax");
    asm("mov 8(%rdi),%rbx");
}