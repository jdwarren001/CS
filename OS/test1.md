# Test #1

## Chapters 2, 4-9

### Chapter 2
    *malloc (sizeofint()) -> return pointer and give space to a pointer

    how to get the address of a function:
        void *worker(void *arg) -> worker (no parentheses)
        pthread_create(..., worker, ...) -> handing over a pointer

    "|" = bitwise OR looking for any bits that come back as all 0's. Comes back flagged true if each one has a 1

    pthread
        void *(*start_routine)(void *)
            - Pointer of an unkown type returned
            - *start_routine: Handing the location of the function
            - void *: Function itself takes a pointer
    I/O:
        open()
        write()
        close()

### Chapter 4 - Processes
    Copy of the Environment 
    The exectubale on disk -> memory
        Code 
        Data 
        Stack -> Local vars, function parameters, return addresses, args
        Heap -> Dynamic data
    File Descriptors
        stdout or cout
        stderr or cerr
        stdin or cin
    Command line arguments
    Return value for operating system

    0x000   | Data (args, environment)
            |
            | Code 
            |
            | Heap v (down)
            |
    0xfff   | Stack ^ (up)

    (Goes up in hex location)

### Chapter 5
    Process API - Basically, your OS and the decider of what to do
    
    fork - duplicates the same process after the fork call (Can be seperated with int = fork())
    exec - Calls diff program  then runs both 
    wait - Waits till different thread is done

### Chapter 6 - Direct execution
     -> Run it on the CPU
    Virualization - It is "at location" but really stored somewhere else 
        (user vs root)
            User -> are unique by exec
            Root/Kernel (Trap Mode) -> Real memory space

    Cooperative OS -> Give up their time slots for others
    Pre-emptive OS -> Has timer-interupt and interupt handler (needs to decide who gets CPU)

### Chapter 7 - CPU Scheduling
    Turnaround time - Time to finish job
    Response Time - Time to start job

    SJF - Shortest Job First
    STCF - Shortest to complete first

    I/O - Runs in the background while others run


### Chapter 8 - MLFQ
    The 5 rules - Go over real quick

### Chapter 9 - Lottery Scheduler 
    Tickets
        Random - FAST
        Currency - Allows own process to allocate most important to run first 
        Stride - Run long only couple, or shorter strides often
        CFS - All get the same run times (Length wise)
        Niceness - Each job gets a rating (-20 will run, high priority; 19 lowest priority)
            Finding Tickets: Red-Black-Trees
    Fairness = job1 / job2