# OS Notes (Chapters 0-9)


### Creating a Thread
    void startThread(ThreadFun *f) {
        //Make a stack frame for the thread I am bringing to life
        //Set paramter registers correctly
        //Invoke function

        // use -> gcc -S -o FunCall.s Funcall.c
        // This will be used to find the memory location we use to store functions
        // should be 64 bit memory
    }


<br><br>
## <b>Kernel and OS</b>
Kernel is the barebones of your system, the 'sudo' operator that builds up a system.
<br>
User space only has access to a <b>micro kernel</b>, and doesn't have full access to the system. Users have <u>'least needed privaleges'</u> theology. 

- Kernel has direct access to memory, boots up system, OS operations, user permissions, memory and addresses, processor timing
- Downsides of Linux: Has a lot of crap. Un-needed kernels.

<br><br>
## <b>fork() and exec()</b>

- fork repeats process of same file and runs both as same time
  - Can be very dangerous and crash computers
- exec runs a different process at the same time

<br><br>
## <b>Process vs Thread</b>
- Process: Runs programs, inputs, outputs, function of PC
- Thread: Same thing, be has seperate run area

<br><br>
## <b>API</b>
API: The broad term and median of which our programs are connected. Basically manages all programs. Is responsible for schedulers, feedback ques, priority and selection. 

<br><br>
## <b> CPU Schedulers </b>
How do we decide who goes next? What job should be done first?

- <u>Metrics</u>
  - Turnaround time: Turnaround = Tcomp - Tarriv
  - >Could do jobs based off fastest complete 
    - <u>FIFO - First come first serve</u>
      - Turn around adds up (ie. turn around for second job is 20 seconds, third is 30, etc.)
      - W/ FIFO, if first job is really large, jobs coming after will increase average mich faster
        - Run the shorter jobs first 
        - SJF (Shortest Job First)
    - <u>STCF (Shortest to Complete First</u>
      - A starts, but A is 100 seconds.
      - B and C arrive, both 10 seconds
      - B and C interupt since they have shorter run times

- <u>New Metric: Response Time</u>
  - Tresp = Tfristrun - Tarrival
  - >How long it takes to start running program
    - <u>SJF:</u> Bad for resp time
      - Takes forever to get to next program since all others have to complete
    - <u>Round Robin</u>: Just run all of them for a few seconds (low response time, but high <b>turnaround time</b>)
      - Should not be so small
      - No progress loading the programs, only context switching
- <u>Overlapping (In addition to previous tactics):</u>
  - Use both the CPU and Disk at same time
  - Can have serious benefits, even if it runs slower on the disk


<br><br>
## <b>Multilevel Feedback Que (MLFQ)</b>

How we schedule what goes next, when programs trade off, how they trade.

- Rules:
  - 1: if priority A > priority B, A runs
  - 2: if priority A = priortiy B, Round Robin runs 
- However, this <b>creates problems:</b> Some processes would never run
  - 3: When first enter system, enters at the top (Fastest Response time)
  - 4a: If job takes a lot of time, its priority falls
  - 4b: If job gives up time slice (on its own), it can stay at priority level and come back
    - 4 -> Basically, if runnning a long time, share the cpu
    - If uses up its time allotment, drops priority even if giving up CPU on its own (given 10ms, drops a few times but uses a lot for 10ms, drops priority still). 
      - They do get more time to run though at lower priority
  - 5: <b>priority boosting</b>: If program being starved, up its priority
- <b>Paramiterization:</b> How do we create a system that knows how to do this?
  - Use calls like 'nice' -> Determines how easily the system will let another pgrogram take control
    - <b>Niceness:</b> -20 to 19
      - Higher niceness means less scheduling 

<br><br>
## <b>Lottery/Proportional Scheduling</b>
How a system determines priority for a system

- Ticket system: Process gets single ticket. (Have a good ticket, get higher priority)
  - <u>Use Randomness:</u> Lightweight, fast, no 'worst-case' scenarios
  - Ticket Currency: Can trade in tickets or 'cash them in' for different processes
  - <b>F (Fairness Metric):</b> job1 / job2 = F
    - 1 = very fair
- Assign Tickets:
  - Stride Sched: Larger strides run less often but possibly longer
    - Short strides run more often, but for shorter times
  - Completely Fair Sched (CFS): All processes get a fair amount of run time
    - Jobs with lower runtimes had run next
- Finding tickets:
  - Red-Black Trees:
    - Use trees to store information
      - Red-Black helps it re-order itself and stay balanced
    - Just used to <u>store the tickets, and easily access them</u>


<br><br>
## <b>Multi-CPU Scheduling</b>

- All CPUs share memory, but can operate and create own caches
- Temperal vs Spatial Locality:
  - Temporal: Specific data being accessed a lot
  - Spatial: Area of data that is being re-used a lot
- <b>Single Que Multiproccessing Scheduling (SQMS)</b>
  - One queue telling what all cores work on
- <b>Multi-Queue Scheduling</b>
  - Multiple queues, most likely will be <u>split up among cores</u>