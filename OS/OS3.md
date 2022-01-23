# Operating Systems Notes

### <b>36 - I/O Devices</b>
> How do we go straight from memory to disk? How do we integrate it in general?
- Direct Memory Access: CPU gives up control of memory and allows disk to take control as well. 
> We need an interface that can operate any interface (USB, hard-drives, GPU, etc)
- Memory Bus (CPU and Memory) -> General I/O Bus (GPU) -> Peripheral I/O Bus (USB and Other)
- Canonical Device: 
  - Interface: Status (On, last used), Command (What it doing), Data (Last keys pressed, grabbed data)
  - Internals: All memory utitlizing this operatinos
  - <b>All under DEV</b>
- Interupts
- POSIX API:
  - Open, Read, Write, Close
  - For all dev tools -> Known as a <b>Driver</b>
    - Runs any device, or operation on pc
- IDE Driver: Basic interface to help interact with devices
  - Handle interrupts
  - wait for drive to be ready
  - start I/O
  - Data transfer
  - Error handling 

### <b>37 - Hard Disks</b>
- Rotational Delay: Delay of the disk rotating
- Seek Time: Delay of the arm moving up and down
- Disk Scheduling:
  - Shortest Seek time
    - <u>Implies the data has to be in order (BAD)</u>

### <b>39 - Files and Directories</b>
- link(): Creates a file
- strace(): Cmd line call that traces and tells user about system calls, arguments, return calls 
- lseek(): Seek into file from certain location (From "whence" point)
  - Whence is an offset of bytes + current location to get to place seeking
- fsync(): Syncs everything to the disk 
  - Makes everything actually done (Before ejecting kinda thing)
- rename(): Renames a file -> An atomic call! Cant be seperated. 
- Info in a file:
  - fstat(): Gets size of file by looking at the end bytes compared to the origin
  - stat():
    - Big struct containting all the info (Times accessed, users, size, ID)
    - Users are assigned a number (user1 -> 0)
- unlink(): Remove a file
- dirent(): Open or close a directory and list the files within
  - name, number, offset, length, type for each file entry
- Hardlinks vs symbolic links:
  - Hardlinks: Two names going to the same address
  - Symobolic Link: Renames the file then goes to the address of the actual named file
- Permission Bits: drwxrwxrwx (you, group, everyone)
  - chmod
  - Each set is one number (777 -> all) (477 -> drw-wrxwrx)

### <b>40 - Writing FS</b>
- Need dirent sruct and stat struct
- Orginization: 
  - Block structure
  - 64 bits to say whether or not a block is in use
    - S: Super lock -> info about file system
    - i: bitmap telling which iblocks are being used
    - d: bitmap telling which data blocks are in use
    - inodes (index node): holds info on the structure of files and such (First 64)
  - Rest of bits for holding data
- inodes like data structure struct()

### <b>42 - FSCK and Journaling</b>
> How do we log things and save if crash?

- Crashing:
  - Atomically: If you something doesn't work, roll back to previous state
  - fsck: Checks all pieces of system to integrity (Bit mapping = to data blocks?)
    - Correct blocks, free blocks, duplicates, bad blocks, directory checks
  - Journaling (write ahead logging): Write everything before as a log, then execute
    - Checkpoints -> once complete, goes back and reuses the journal area
- Recovery:
  - Reads log and replayed if needing to re-do transactions

### <b>44 - Flash SSD</b>
> How do we decrease the wear of the device?
- Solution: Change the area of the saves, giving each byte a longer lifespan
  - SLC vs TLC: Store one bit per cell or 3 per cell. (SLC faster)
  - Come in groups of bits:
    - Want to re-use sector of bit? -> Have to move all data from bit then use entire sector