# Operating Systems Notes

### <b>13 - Abstraction Process</b>
- Protections: Each program has their own virtual space
  - Go outside of this, get flagged for seg fault
- Principle of Isolation: Only use the permissions needed, secuirty and protections

### <b> 14 - Memory API </b>
- Stack Memory: Local data <b>(Implicit)</b>
- Heap Memory: Global data <b>(Explicit)</b>
  - int *x = (int *) malloc(sizeof(int);)
  - Always decalred in an even number (for purpose of creating arrays)
- free(): Frees unused heap for use
  - Make sure to reserve memory for this!
  - Else we get a seg fault
    - Use malloc -> char *dst = (char *) malloc(strlen(src) +1);
  - Memory leaks, freeing before you're done with it -> Creates issues
  - Call malloc again, need to free up space again
- Purify and valgrind: Both are helpers to find memory leaks and manage memory 
- <b>Memory leaks occur if malloc() is not paired with free()</b>

### Code
    int main() {
        char src* = (char *)malloc(sizeof(char)*10);
    }

  - malloc_hook: Grabs all calls of free and malloc
  > <span style="color:red">malloc = new; free = delete</span>

### <b>15 - Address Translation</b>
> Conversion from <u>physical address to virtualized address</u>
- <u>Physical Address</u>: Virtual Address + Base
  - Gets to the virtualized area of memory that creates the whole memory our program sees
- <b>Memory Management Unit (MMU)</b>: Only available to the kernel -> NO user
- Free List: Pointers pointing to the chunks of free memory

### <b>16 - Segmentation</b>
> Cut up memory into usable chunks
- Segment Register: Holds location of seperate segment 
  - First 2 numbers are segment indicator (00 -> seg 1; 01 -> seg 2)
  - Rest of numbers are the offset
  - Add together segment and offset and get register addresss
    - Has overlapping (first two numbers move to end of offset number)
- Protection Bits: Only allows certain permissions to be done by memory (heap, stack)

### <b>17 - Free Space Managment</b>
> How memory is allocated and seprated for use
- If memory is freed up:
  - Ends up having multiple sections seperated but free
  - Memory is then re-ordered and strung together to give a more accurate summation of the free memory
- Getting memory:
  - hptr:
    - size -> 20 bytes
    - magic number -> Serves as a seperation between header code and what the user is doing with the code
  - ptr:
    - 20 bytes that user called
- Magic vs Next:
  - Magic is allocated space that is going to be used by user
  - Next is unallocated memory that can be grabbed from the free space
- Linked list :
  - > Kind of a MEMORY list. Piece together memory into a usable memory list
  - If two seperate sections are connected in memory -> Connect into one memory
  - Types of fitting:
    - Best fit -> Takes awhile but leaves small chunk. Little waste. 
    - Worst fit -> Does not perform well. Leaves big chunks.
    - First fit -> First possible place it goes in
    - Next fit -> Goes down the list for next usable space. Uniform fitting. 
  - Buddy Allocation: Helps system know what memory is next to eachother. Speeds searches up. 
    - Knows the chunks near it

### <b>18 - Paging</b>
> Memory segments and how to sort/find them
- Paging: Works with memory in fixed blocks for caches (8, 16, 32... "pages 1, 2, 3...")
- Segmentation: Arbritrary size, any amount for chaches (as much as the user asks)
  - Page: can be out of order (the actual memory used)
  - Page Frame: in order and breaks up the sections
- Virtual Page Number (VPN): Much like segmentation, but tells <b>Page number</b> then <b>offset number</b>.
  - 0|1|0|1|0|1
    - First two is VPN
    - Next 4 is the offset 
  - This is then translated to a physical address (PFN)
- Physical Page Number (PFN): Same as VPN but actual address
  - 3x4
  - 1|1|1|0|1|0|1
- (%eax) - grabbing the location of the eax
- %eax - grabbing the memory of the eax

### <b>19 - Translation Lookaside Buffer</b>
> Speeds up memory translation
- Just orginizes memory in specific ways to utilize it better
- <u>A library of popular virtual to physical translations</u> used to speed up this process
  - A "hit" if able to use the the TLB
  - "Miss" if not able to use it

### <b>21 - Swapping (Mechanisms)</b>
- <u>DIFFERENT Virtual Memory</u>: Means swap space in Windows interface
> How do we beat memory limitations?
- Swap Space: Chunk of disk with <b>no file access</b> (Not under root)
  - Not used much, put in to free up real memory
  - Holds the current and upcoming processes, swaps in and out ones that need to run and stop
- Page Table Entry (PTE): Similar to the TLB, a table looking for pages of memory and if its being used in the physical memory or not (hit or not)
  - Page Fault: Not always bad, just a special situation that can be dealt with deifferently than normal
  - Page fault handler: Handles the fault or exception procedures that come next
- Code: 
  - AccessMemory() -> Grabs what is in memory
  - DiskRead() -> used to read these sections for what is in these sections and what we can do with this memory
- High/Low Watermarks: Tells when to start deleting pages to not run over memory
  - If HW has less than the LW left in memory, starts evicting
  - The space is freed using a <b>page daemon</b>


### <b>22 - Swapping Policies</b>
> How and when do we kick out processes?
- Average Memory Access Time (AMAT): How good computer memroy performs
  - AMAT = TM + (PMiss · TD) 
    - TM = Cost of accessing memory
    - TD = Cost of accessing disk
    - Pmiss = Finding data in the cache
> Is the memory swapping too early? Wasting memory swaps when the memory can take more?
- Wich blocks do we switch out for?
  - FIFO
  - Random
  - LFU (Least frequently used): Haven't needed that much, toss it
  - LRU (Least Recently Used): Haven't used that page in awhile, dont need that page
- Principle of Locality: Dont jump all over, stay pretty close to origin
- Thrashing: Memory is over-used and can only page to the next operation

### <b>26 - Concurrency</b>
> What is a thread safe library?
- If thread bomb goes off, only <b>the process</b> is at risk. That process allocates a bunch of stacks for the thread and probably gets booted since that process is overloading, not the whole memory. 
  - Has multiple thread per process, rather than an entire seperate process
> Why use threads?
- Utilize your cores, and your memory better.
>Problem to solve:
- What if threads are trying to share data?
  - Global data
  - Cant even increase a counter -> we lose our spot
- Can <b>synchronize</b> to get around this. 
  - Only one thread can use the function (such as a counter increment function) at a time

### <b>28 - Lock</b>
> Locks in a process to complete as if it was the only process
- Must assign it to a variable -> lock_t <b>mutex</b>
  - Mutex = Locks or unlocks the function for others to use
- lock(&mutex) -> Locks that variable
- creating your own lock:
  - Stop interrupts
    - Lock interrupts when locking process
    - Unlock when freeing for another
- Many negatives
  - No new data coming in. System us useless till operation is done.
- LoadLinked() -> Grabs info fromm memory, helps for updating locks
- FetchAndAdd() -> Increments a value whiler returning the old value
- Instead of Sleeping: Have a queue where we wait to go next for lock

### <b>29 - Locked Data Structures</b>
> How do we add locks so that data structures still work correctly?
- Concurrent Linked List: 
  - Lock the creation of the new element
    - pthread_mutex_lock(&L->lock);
    - new->next = L->head;
    - L->head = new;
    - pthread_mutex_unlock(&L->lock);
  - Unlock after new list created
  - Start inserting/looking/<b>playing with pointers at all, must lock!</b> Otherwise, you get lost. Pointer deleted mid search.
> <b>Only lock small area you need!!!</b>
- Queues:
  - Only worry about front and back
  - Lock/unlock both seperately
    - Don't have to worry about middle section

### <b>30 - Condition Variables</b>
> Freeze a variable till some action has occured
- Very similar to locks, but for vars and serves slightly different purpose
- More diverse
- <b>Volatile:</b> Keep this var in regi (not overwritten or lost, usable fast)
- Waiting and Signal:
  - Variable waiting to be edited
    - pthread_mutex_lock(&var2);
    - pthread_cond_wait(&var1, &var2); -> Using while loop
    - pthread_mutex_unlock(&var2);
  - Signal from some action (another var changing or some) then yells that it has changed to entire function.
    - pthread_cond_signal(&var1);
- If both released by same signal, could create issues if they have a specific order to execute. Could exit before finishing, could mess up pointers, etc. 
- Great for a sender/consumer formula -> Cant send more than you can consume (Send one, consume one)
> Mutex -> Lock and unlock

> Condition -> Singal and wait

### <b>31 - Semaphores</b>
> A lot like mutex, but can have multiple running at the same time, deals with an int instead of undeclared data type. 
- sem_wait()
- sem_post()
  - Very similar to mutex and conditional vars but uses 1's and 0's to signal (incr and decr)
- Dining Problem -> Everyone needs forks but get locked and cannot pass since other people (processes) took them already
  - Both parties relying on something that only one can have at a time

### <b>32 - Concurrency Problems</b>
> Common problems with making everything sync up (Threads and such)
- Deadlock: Each process gets stuck waiting for another process or itself, and gets stuck.
- Two types of non-deadlock concurrency issues:
  - Atomicity: Threads return values that screw up other threads
  - Order violation: Thread needing info from another thread runs first, seg faulting since that data hasnt happened yet. 
- Deadlock concurrency issues: The dining problem
- Four things that create Deadlock:
  - > Missing one, no deadlock
  - Mutual Exclusion: Need an item exclusively 
  - Hold-and-wait: Hold items while waiting for another resource
  - No preemption: Cannot steal item from another thread using it
  - Circular Wait: Circular chain of threads such that each holds an item the other is waiting for. 
- Solutions:
  - Lock Ordering: Layer locks so that lower orders go first

    lock(&m1)

    lock(&m2)

    CODE

    unlock(&m2)

    unlock(&m1)
  - Detect and Recover: Stuff should be happening every ten seconds, check, and if locked, doesn't happen, so reset the process. 
- LiveLock: Stuck in a loop of locking and unlocking and never making progress

### <b>33 - Event based Concurrency</b>
> What if we didn't use a context switch? Big list of things waiting to use the cpu. Each just gets the cpu and then the next goes. 
- select() and poll() -> Selects what gets the I/O next
- Blocking and Non-Blocking: 
  - Blocking: Does the entire operation before returning
  - Non-Blocking: Does a small amount of work then returns and hits other operations
- NO LOCKS