#include <iostream>
#include <unistd.h>

using namespace std;

typedef void ThreadFun(int threadNum);

struct Context {
  long rdi;
  long rsp;
  long rax;
  long rbx;
  long rcx;
  long rdx;
  long rsi;
  long rip;
  long rbp;
};

Context threadStates[3];
char *stack; // make an array of stacks
int currentThread = 0;
int numberOfThreads = 1;

void saveRegs(Context *p) {
  asm("mov %rdi, (%rdi)");
  asm("mov %rsp, 8(%rdi)");
  asm("mov %rax, 16(%rdi)");
  asm("mov %rbx, 24(%rdi)");
  asm("mov %rcx, 32(%rdi)");
  asm("mov %rdx, 40(%rdi)");
  asm("mov %rsi, 48(%rdi)");
  // asm("mov %rip, 56(%rdi)");
  asm("mov %rbp, 64(%rdi)");
}

void loadRegs(Context *p) {
  asm("mov (%rdi), %rdi");
  asm("mov 8(%rdi), %rsp");
  asm("mov 16(%rdi), %rax");
  asm("mov 24(%rdi), %rbx");
  asm("mov 32(%rdi), %rcx");
  asm("mov 40(%rdi), %rdx");
  asm("mov 48(%rdi), %rsi");
  // asm("mov 56(%rdi), %rip");
  asm("mov 64(%rdi), %rbp");
}

void sharecpu(int threadNum) {
  Context *c;
  c = &threadStates[currentThread];
  saveRegs(c);
  currentThread = rand()%numberOfThreads;
  c = &threadStates[currentThread];
  loadRegs(c);
}

void launchThread(ThreadFun *MainPtr, void *stack) {
    asm("mov %rsi,%rsp"); //rsi is SECOND argument, put in the stack pointer
    currentThread += numberOfThreads - 1;
    MainPtr(currentThread);
}

void createThread(ThreadFun *MainPtr) {
    stack=(char *)malloc(64000)+64000;
    numberOfThreads++;
    Context *c;
    c = &threadStates[currentThread];
    saveRegs(c);
    launchThread(MainPtr, stack);
}


/* Change nothing below this line.  Get the program to execute the code
 * of main, main1, and main2
 * It does not matter the order that the code for main, main1, and 
 * main2 gets executed, but it should execute a piece of the code
 * and then use sharecpu to gives other threads a chance to execute.
 */

void main1(int threadNum) {
  for (int i=0;i<10;i++) {
      cout << "Main 1 says Hello" << endl;
      usleep(1000);
      sharecpu(threadNum);
  }
}

void main2(int thread) {
  for (int i=0;i<10;i++) {
    cout << "Main 2 says Hello" << endl;
    usleep(1000);
    sharecpu(thread);
  }
}

int main() { 
  createThread(main1);
  cout << "Back to Main" << endl;
  createThread(main2);
  while (true) {
        cout << "Main says hello" << endl;
        usleep(100);
        sharecpu(0);
  }
  return 0;
}
