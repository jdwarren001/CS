# Final Notes
    Thursday 10:00pm Dec 16th
    100% MC, 30 Questions
    All chapters 
        4-9, 13-19, 21-22, 26-32, 36-37, 39, 40, 42
    
    Code: 
        Malloc + Free
        Threads
            Create
            passing pointers [I = *Iptr=(I *)arg]
            return pointers [return (void *)&o]
        Malloc and Thread Bombs
        STAT
        DIRENT

        Context Switch
            Regis used to pass arguments

        Process
            Difference between thread and process
            5 - Fork and exec
            6 - Direct execution
                Exe cant run somewhere else in memeory
                Limited
                    User vs root - Permissions
            7 - Mulitple Processes
                Who gets cpu?
            8 - Sharing CPU
                MLFQ
            9 - Lottery

        Memory
            13 - Passed thinking about memroy (virtualization)
                Old: Big block and fill it up
                    Virtualization -> Does this on a small scale
            14 - Free/Malloc
                Malloc hook/free hook
                Valgrind
            15 - Address Translation
                User vs root (with memory and location)
            16 - Segmentation
                How we deal with that memory and break it up
            17 - How we keep track of those changes and such
                Linked list of free
                Coalesce into bigger blocks
            18 - Paging
                Cache/address translation
            19 - Impliment cache and finding those free spaces
            21 - Swap
                Segment of disk for shortage of RAM - Slow
            22 - How to use swap 
        
        Concurrency
            27 - Thread and create thread
            28, 29, 30 - Consequences of threads/processes
                Locks, locked data structures
                Conditional vars
            31 - Semaphores 
                Solve all?
            32 - Bugs
                Deadlock
                Atomicity
                Order failures
            
        Persistance
            36 - I/o device is a "file"
                Permissions structures
                Drivers has similar structures 
                Windows - TWAIN 
                    Scanners - Can only have one at a time
            37 - Spinning disks
                What are delays in writing data?
                    Tracks and sectors take a sec 
            39 - DIRENT and STAT
                Get stats for a file
                Get the files in a folder
            40 - Toy implimentation
                Super block
                ibitmap
                dbitmap
                    Compact way saying that part of the disk is in use
                inode
                data blocks
            42 - Journaling and FSCK
                File updating in case of crash
                Check if file system is good