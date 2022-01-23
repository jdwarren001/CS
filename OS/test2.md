# OS Test 2

## Chapters 13-22 and 26-32


> Reading Writing

    Malloc Bomb
    Thread Bomb
    mutex
        pthread_mutex_lock(&x);
        pthread_mutex_unlock(&x);
    cond var
        pthread_cond_signal(&x);
        pthread_cond_wait(&x, &x2);
    malloc
        void *malloc(size_t size);
        int x* = (int *) malloc(sizeof(int));
    free
        free(x);

> Address Space

    Code
    heap
    v
    ^
    stack

    - Seperation user/root space
      - User only gets virtual memory
      - Root gets access to it all and TLB

    - malloc_hook() and free hook
    - Memory Leaks

> Address Translation

    user/root
    Not seeing actual memory 

> Segmentation

    Slicing physical virtual memory 

> Swap

    Understand premise - Extend memory to include all of disk space

> No context switch

    - But, knowing why a=a+1 concurrency causes issues with threading
    - (void *) (threadfun*)(void *)
    - Pthread library
      - create thread
      - join thread
      - mutex
        - lock/unlock
      - cond var
        - signal/wait

> Concurrency Bugs

    Dead Lock
    Dining Philosophers 
    Atomicity - Failure to add locks
    Order Violation - Nothing to enforce order 
    Live Lock - Gets stuck, still operating, but endless loop or something

    Conditions of Deadlock:
    - Mutual Exclusion: Grab it
    - Hold-and-Wait: Hold resources while waiting for another
    - No preemption: Cant take it from another
    - Circular wait: Circular chain connecting threads