# comp3231ass1

## ASST1: Synchronisation

Table of Contents

-   [Due Dates and Mark Distribution](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#due-dates-and-mark-distribution)
    -   [Deliverables](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#deliverables)
    -   [Final Mark Computation](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#final-mark-computation)
-   [Introduction](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#introduction)
-   [Setting Up Your Assignment](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#setting-up-your-assignment)
    -   [Obtain the ASST1 distribution with git](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#obtain-the-asst1-distribution-with-git)
    -   [Configure OS/161 for Assignment 1](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#configure-os-161-for-assignment-1)
    -   [Building ASST1](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#building-asst1)
    -   [Check sys161.conf](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#check-sys161-conf)
    -   [Run the kernel](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#run-the-kernel)
    -   [Kernel menu commands and arguments to OS/161](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#kernel-menu-commands-and-arguments-to-os-161)
-   [Concurrent Programming with OS/161](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#concurrent-programming-with-os-161)
    -   [Debugging concurrent programs](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#debugging-concurrent-programs)
-   [Tutorial Exercises](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#tutorial-exercises)
-   [Code reading](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#code-reading)
    -   [Thread Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#thread-questions)
    -   [Scheduler Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#scheduler-questions)
    -   [Synchronisation Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#synchronisation-questions)
-   [Deliverable 1: Coding the Assignment](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#deliverable-1-coding-the-assignment)
    -   [Part 1: The Concurrent Counter Problem](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#part-1-the-concurrent-counter-problem)
        -   [Your Task](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#your-task)
    -   [Part 2: Bounded-buffer producer/consumer problem](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#part-2-bounded-buffer-producer-consumer-problem)
        -   [The files:](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#the-files)
        -   [Clarifications](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#clarifications)
    -   [Part 3: The CDROM](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#part-3-the-cdrom)
        -   [Hints](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#hints)
-   [Deliverable 2: Video Overview](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#deliverable-2-video-overview)
-   [Submitting](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#submitting)

# [Due Dates and Mark Distribution](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-1)

**Updated Due Date & Time**: 2pm (14:00), March 11th (Week 5)

**Due Date & Time:** 4pm (16:00), March 8th (Week 4)

**Marks:** Worth 20 marks towards the overall course total of 100.

## [Deliverables](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-2)

> -   A *coded solution* to the problems specified below (**C** geometrically weighted at 70%).
> -   A *recorded video* overview of your solution (**V** geometrically weighted at 30%).

## [Final Mark Computation](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-3)

The assignment mark will be determined from a weighted geometric mean of the two assessed components, i.e. as follows:

Mark = 20*(C/14)^0.7*(V/6)^0.3

# [Introduction](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-4)

In this assignment you will solve a number of synchronisation problems within the software environment of the OS/161 kernel. By the end of this assignment you will gain the skills required to write concurrent code within the OS/161 kernel. While the synchronisation problems themselves are only indirectly related to the services that OS/161 provides, they solve similar concurrency problems that you would encounter when writing OS code.

The Week 3 tutorial contains various synchronisation familiarisation exercises. Please prepare for it. Additionally, feel free to ask any assignment related questions in the tutorial.

# [Setting Up Your Assignment](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-5)

We assume after the WARMUP that you now have some familiarity with setting up for OS/161 development. The following is a brief setup guide. If you need more detail, refer back to the WARMUP.

## [Obtain the ASST1 distribution with git](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-6)

Clone the ASST1 source repository from `nw-syd-gitlab.cseunsw.tech`.

% cd ~/cs3231
% git clone https://z8888888@nw-syd-gitlab.cseunsw.tech/COMP3231/24T1/z8888888-asst1.git asst1-src

## [Configure OS/161 for Assignment 1](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-7)

Configure your new sources as follows.

% cd ~/cs3231/asst1-src
% ./configure && bmake && bmake install

We have provided you with a framework to run your solutions for ASST1. This framework consists of tester code (found in `kern/asst1`) and menu items you can use to execute the code and your solutions from the OS/161 kernel boot menu.

You have to configure your kernel itself before you can use this framework. The procedure for configuring a kernel is the same as in the WARMUP, except you will use the ASST1 configuration file:

% cd ~/cs3231/asst1-src/kern/conf
% ./config ASST1

You should now see an ASST1 directory in the `kern/compile` directory.

## [Building ASST1](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-8)

When you built OS/161 for WARMUP, you ran `bmake` in `compile/WARMUP`. In ASST1, you run `bmake` from (you guessed it) `compile/ASST1`.

% cd ../compile/ASST1
% bmake depend
% bmake
% bmake install

If you are told that the `compile/ASST1` directory does not exist, make sure you ran `config` for ASST1.

Tip: Once you start modifying the OS/161 kernel, you can quickly rebuild and re-install with the following command sequence. It will install the kernel if the build succeeds.

% bmake && bmake install

## [Check sys161.conf](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-9)

The `sys161.conf` should be already be installed in the `~/cs3231/root` directory from the warmup. If not, follow the instructions below to obtain another copy. A pre-configured sys161 configuration is available here: [sys161.conf](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/sys161.conf).

% cd ~/cs3231/root
% wget http://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/sys161.conf

## [Run the kernel](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-10)

Run the previously built kernel:

% cd ~/cs3231/root
% sys161 kernel
sys161: System/161 release 2.0.8, compiled Feb 25 2019 09:34:40

OS/161 base system version 2.0.3
(with locks&CVs solution)
Copyright (c) 2000, 2001-2005, 2008-2011, 2013, 2014
President and Fellows of Harvard College. All rights reserved.

Put-your-group-name-here's system version 0 (ASST1 #1)

16220k physical memory available
Device probe...
lamebus0 (system main bus)
emu0 at lamebus0
ltrace0 at lamebus0
ltimer0 at lamebus0
beep0 at ltimer0
rtclock0 at ltimer0
lrandom0 at lamebus0
random0 at lrandom0
lser0 at lamebus0
con0 at lser0

cpu0: MIPS/161 (System/161 2.x) features 0x0
OS/161 kernel [? for menu]:

## [Kernel menu commands and arguments to OS/161](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-11)

Your solutions to ASST1 will be tested (and automarked) by running OS/161 with command line arguments that correspond to the menu options in the OS/161 boot menu.

Caution!

**Do not** change these menu option strings!

Here are some examples of using command line arguments to select OS/161 menu items:

sys161 kernel "at;bt;q"

This is the same as starting up with `sys161 kernel`, then running "at" at the menu prompt (invoking the array test), then when that finishes running "bt" (bitmap test), then quitting by typing "q".

sys161 kernel "q"

This is the simplest example. This will start the kernel up, then quit as soon as it's finished booting. Try it yourself with other menu commands. Remember that the commands must be separated by semicolons (";").

# [Concurrent Programming with OS/161](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-12)

If your code is properly synchronised, the timing of context switches, the location of `kprintf()` calls, and the order in which threads run should not influence the correctness of your solution. Of course, your threads may print messages in different orders, but you should be able to verify that they implement the functionality required and that they do not deadlock.

## [Debugging concurrent programs](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-13)

`thread_yield()` is automatically called for you at intervals that vary randomly. `thread_yield()` context switches between threads via the scheduler to provide multi-threading in the OS/161 kernel. While the randomness is fairly close to reality, it complicates the process of debugging your concurrent programs.

The random number generator used to vary the time between these `thread_yield()` calls uses the same seed as the random device in System/161. This means that you can reproduce a specific execution sequence by using a fixed seed for the random number generator. You can pass an explicit seed into the random device by editing the "random" line in your `sys161.conf` file. For example, to set the seed to 1, you would edit the line to look like:

28 random seed=1

We recommend that while you are writing and debugging your solutions you start the kernel via command line arguments and pick a seed and use it consistently. Once you are confident that your threads do what they are supposed to do, set the random device to autoseed. This should allow you to test your solutions under varying timing that may expose scenarios that you had not anticipated.

To reproduce your test cases, you need to run your tests via the command line arguments to sys161 as described above, otherwise system behaviour will depend on your precise typing speed (and not be reproducible for debugging).

# [Tutorial Exercises](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-14)

The aim of the week 3 tutorial is to have you implement synchronised data structures using the supplied OS synchronisation primitives. See the [Week 03 Tutorial](https://cgi.cse.unsw.edu.au/~cs3231/tutorials.php) for details.

It is useful to be prepared to discuss both the questions and the following assignment in your tutorial.

# [Code reading](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-15)

The following questions aim to guide you through OS/161's implementation of threads and synchronisation primitives in the kernel itself for those interested in a deeper understanding of OS/161. A deeper understanding can be useful when debugging, but is not strictly required, though recommended especially for Extended OS students. I cover some of these questions in the Extended lecture, so feel free to review the lectures even if you are not enrolled in the course.

For those interested in gaining a deeper understanding of how synchronisation primitives are implemented, it is helpful to understand the operation of the threading system in OS/161. After which, walking through the implementation of the synchronisation primitives themselves should be relatively straightforward.

## [Thread Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-16)

1.  What happens to a thread when it exits (i.e., calls `thread_exit()`)? What about when it sleeps?
2.  What function(s) handle(s) a context switch?
3.  How many thread states are there? What are they?
4.  What does it mean to turn interrupts off? How is this accomplished? Why is it important to turn off interrupts in the thread subsystem code?
5.  What happens when a thread wakes up another thread? How does a sleeping thread get to run again?

## [Scheduler Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-17)

1.  What function is responsible for choosing the next thread to run?
2.  How does that function pick the next thread?
3.  What role does the hardware timer play in scheduling? What hardware independent function is called on a timer interrupt?

## [Synchronisation Questions](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-18)

1.  What is a wait channel? Describe how `wchan_sleep()` and `wchan_wakeone()` are used to implement semaphores.
2.  Why does the lock API in OS/161 provide `lock_do_i_hold()`, but not `lock_get_holder()`?

# [Deliverable 1: Coding the Assignment](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-19)

We know: you've been itching to get to the coding. Well, you've finally arrived!

**This is an assessable component of this assignment.**

The following problems will give you the opportunity to write some fairly straightforward concurrent systems and get a practical understanding of how to use concurrency mechanisms to solve problems. We have provided you with basic tester code that starts a predefined number of threads that execute a predefined activity (in the form of calling functions that you must implement or modify).

**Note:** In this assignment, you are restricted to the *lock*, *semaphore*, and *condition variable* primitives provided in OS/161. The use of other primitives such as `thread_yield()`, *spinlocks*, interrupt disabling (_spl_), atomic instructions, and the like are **prohibited**. Moreover, they usually result in a poor solution involving busy waiting.

**Note:** In some instances, the comments within the code also form part of the specification and give guidance as to what is required. Make sure you read the provided code carefully.

Check that you have specified a seed to use in the random number generator by examining your `sys161.conf` file, and run your tests using System/161 command line arguments. It is much easier to debug initial problems when the sequence of execution and context switches are reproducible.

When you configure your kernel for ASST1, the tester code and extra menu options for executing the problems (and your solutions) are automatically compiled in.

## [Part 1: The Concurrent Counter Problem](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-20)

**Approximate Mark Contribution: 20%**

For the first problem, we ask you to solve a mutual exclusion problem. The code in `kern/asst1/counter.c` is an incomplete implementation of an interface specified in `kern/asst1/counter.h`. The interface specifies functions to initialise (`counter_initialise()`), increment (`counter_increment()`), decrement (`counter_decrement()`), and read and cleanup a synchronised counter (`counter_read_and_destroy()`). All functions can be called concurrently by multiple threads and are unsynchronised.

The testing code provided in `kern/asst1/counter_tester.c` exercises a subset of the counter code and produces an incorrect result similar to the following. Note that the final count of the incomplete implementation *is* dependent on scheduling and hence will vary.

OS/161 kernel [? for menu]: 1a
Starting 10 incrementer threads
The final count value was 5083 (expected 10000)

### [Your Task](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-21)

Your task is to modify `kern/asst1/counter.c` and `kern/asst1/counter.h` by synchronising the code appropriately such that synchronised counters can be created, destroyed, incremented and decremented correctly.

You can assume `counter_read_and_destroy()` is called after a call to `counter_initialise()` with a valid pointer originally provided by `counter_initialise()`. For each valid pointer provided by `counter_initialise()`, `counter_read_and_destroy()` will only be called once. `counter_increment()` and `counter_decrement()` are only ever called (multiple times) with a valid pointer originally provided by `counter_initialise()` and before the final call to `counter_read_and_destroy()`.

To test your solution, use the `1a` menu choice. Sample output from a correct solution in included below.

OS/161 kernel [? for menu]: 1a
Starting 10 incrementer threads
The final count value was 10000 (expected 10000)

When we mark your assignment, we will replace the testing code provided in `kern/asst1/counter_tester.c` to test your implementation more extensively than the provided code.

## [Part 2: Bounded-buffer producer/consumer problem](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-22)

**Approximate Mark Contribution: 30%**

Your next task in this part is to synchronise a solution to a producer/consumer problem. In this producer/consumer problem, one or more *producer* threads allocate data structures, and call `producer_send()`, which copies pointers to the data structures into a fixed-sized buffer, while one or more *consumer* threads retrieve those pointers using `consumer_receive()`, and inspect and de-allocate the data structures.

The code in `kern/asst1/producerconsumer_tester.c` starts up a number of producer and consumer threads. The producer threads attempt to send pointers to the consumer threads by calling the `producer_send()` function with a pointer to the data structure as an argument. In turn, the consumer threads attempt to receive pointers to the data structure from the producer threads by calling `consumer_receive()`. **These functions are currently partially implemented. Your job is to synchronise them**.

Here's what you might see before you have implemented any code:

OS/161 kernel [? for menu]: 1b
run_producerconsumer: starting up
Waiting for producer threads to exit...
Consumer started
Producer started
Consumer started
Producer finished
Consumer started
Producer started
**_ Error! Unexpected data -2147287680 and -2147287680
Consumer started
_** Error! Unexpected data -2147287712 and -2147287712
Consumer started
**_ Error! Unexpected data -2147287648 and -2147287648
_** Error! Unexpected data -2147287712 and -2147287712
**_ Error! Unexpected data -2147287648 and -2147287648
_** Error! Unexpected data -2147287648 and -2147287648
**_ Error! Unexpected data -2147287648 and -2147287648
_** Error! Unexpected data -2147287712 and -2147287712
**_ Error! Unexpected data -2147287664 and -2147287664
_** Error! Unexpected data -2147287664 and -2147287664
**_ Error! Unexpected data -2147287600 and -2147287600
_** Error! Unexpected data -2147287600 and -2147287600
**_ Error! Unexpected data -2147287664 and -2147287664
_** Error! Unexpected data -2147287600 and -2147287600
panic: Assertion failed: fl != fl->next, at ../../vm/kmalloc.c:1134 (subpage_kfree)

Note that code will panic (crash) in different ways depending on the timing.

And here's what you will see with a (possibly) correct solution:

OS/161 kernel: 1b
run_producerconsumer: starting up
Consumer started
Waiting for producer threads to exit...
Producer started
Consumer started
Consumer started
Producer started
Consumer started
Consumer started
Producer finished
Producer finished
All producer threads have exited.
Consumer finished normally
Consumer finished normally
Consumer finished normally
Consumer finished normally
Consumer finished normally

### [The files:](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-23)

-   `producerconsumer_tester.c`: Starts the producer/consumer simulation by creating producer and consumer threads that will call `producer_send()` and `consumer_receive()`. You are welcome to modify this simulation when testing your implementation --- in fact, you are encouraged to --- but remember that it will be overwritten when we test your solution is tested, so you can't rely on any changes you make in this file.
-   `producerconsumer.h`: Contains prototypes for the functions in `producerconsumer.c`, as well as the description of the data structure that is passed from producer to consumer (the uninterestingly-named `data_item_t`). This file will also be overwritten when your solution is tested by us.
-   `producerconsumer.c`: Contains the implementation of `producer_send()` and `consumer_receive()`. It also contains the functions `producerconsumer_startup()` and `producerconsumer_shutdown()`, which you can implement to initialise any variables and any synchronisation primitives you may need.

### [Clarifications](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-24)

The provided data structure represents a bounded buffer capable that is capable of holding `BUFFER_ITEMS` `data_item_t` pointers. This means that calling `producer_send()` `BUFFER_ITEMS` times should not block (or overwrite existing items, of course), but calling `producer_send()` one more time **should** block, until an item has been removed from the buffer using `consumer_receive()`. We have provided an unsynchronised skeleton of circular buffer code, though you will have to use appropriate synchronisation primitives to ensure that concurrent access is handled safely.

The data structure should function as a circular buffer with first-in, first-out semantics.

## [Part 3: The CDROM](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-25)

**Approximate Mark Contribution: 50%**

This part simulates a read-only storage device similar to a CDROM. At a high level, an API is provided for client threads to send requests to read the values out of blocks on the cdrom. A single handler thread reacts to read requests completing, and eventually arranges for the original requests to complete with the value contained in the cdrom block.

In more detail, your task is to complete and synchronise the following functions provided in `cdrom.c`.

> -   `cdrom_read()` is called by client threads to read the value contained in a specified cdrom block. We provide the function `cdrom_block_request()` which can be called to make the request to the cdrom framework. Note: `cdrom_block_request()` simply makes the request and returns immediately, i.e. before the result is available. You must extend `cdrom_read()` to block the current client thread on a synchronisation primitive until the result is available. You also need to add some shared state such that the eventual result can be returned to this function.
> -   `cdrom_handler()` is called by our framework whenever the value is available for a previously issued `cdrom_block_request()`. The function is passed the block number of the original request and the value associated with it now it's available. Your task is to complete `cdrom_handler()` such that is wakes up the thread that originally made the request and makes available the received value to that thread.
>
> Note: The there is an additional contraint on the calling of `cdrom_block_request()`. Like real hardware, our framework supports a maximum number of outstanding cdrom requests at a time. This practically means that your solution can call `cdrom_block_request()` a maximum number of times before `cdrom_handler()` is called by our framework. Phrased differently, the number of times `cdrom_block_request()` is called minus the number of times `cdrom_handler()` is called must never exceed `MAX_CONCURRENT_REQ`. Your solution should block until a further request would not violate the contraint.

The code that drives the system is in `cdrom_tester.c` and `cdrom_client.c`. You should review the code to develop an understanding of the system. You'll see it starts a number of client threads and a handler thread and then waits for the clients to issue all their requests and exit. The code also waits for the handler thread to exit after the outstanding requests have been made and the clients hanve left.

The functions of particular interest are `cdrom_client_thread()` and `cdrom_handler_thread()` which document and show the behaviour of clients and the handler.

**Your task is to implement the** `cdrom_read()` **and** `cdrom_handler()` **functions as described above and in the code itself such that the cdrom system will execute correctly with all the requests processed.**

-   Your solution should not busy-wait when a thread can't make progress.
-   You should not rely on any changes to code in the `cdrom_tester.c`, `cdrom_client.c`, `cdrom_tester.h` or `cdrom.h` files. They will be changed for automated testing purposes after your final submission. You can vary the code for your own testing purposes, but we'll replace them for our own testing, thus you should confirm your code continues to work with the originally provided configuration after completing your own testing.

A sample of how the as-provided code can fail follows. Notice the client ends up with a incorrect value for the block it requested. The system is neither synchronised nor making the value available to the client.

cpu0: MIPS/161 (System/161 2.x) features 0x0
OS/161 kernel: 1c
run_cdrom: starting up
Waiting for tester threads to exit...
CDROM client thread 0 started
Received request read block 0
Thread 0 requested block 0 an received value 0
panic: Got an unexpected value from the requested block

A potentially correct solution generates output similar to that below for the provided test case.

Note: The interleaving of progress of individual threads can vary between each run of the simulation. However, clients should always receive the value associatied with the block they requested.

cpu0: MIPS/161 (System/161 2.x) features 0x0
OS/161 kernel: 1c
run_cdrom: starting up
Waiting for tester threads to exit...
CDROM client thread 0 started
Interrupt thread thread 0 started
Received request read block 0
CDROM client thread 1 started
Received request read block 0
Thread 0 requested block 0 an received value 305419896
CDROM client thread 2 started
Thread 1 requested block 0 an received value 305419896
Received request read block 1
Received request read block 0
Received request read block 1
Thread 0 requested block 1 an received value 305419897
Received request read block 2
Thread 1 requested block 1 an received value 305419897
Thread 2 requested block 0 an received value 305419896
Thread 0 requested block 2 an received value 305419898
Received request read block 3
Received request read block 1
Received request read block 2
Thread 0 requested block 3 an received value 305419899
Thread 2 requested block 1 an received value 305419897
Thread 1 requested block 2 an received value 305419898
Received request read block 3
Received request read block 2
Received request read block 4
Thread 1 requested block 3 an received value 305419899
Thread 2 requested block 2 an received value 305419898
Received request read block 3
Received request read block 4
Thread 0 requested block 4 an received value 305419900
Thread 2 requested block 3 an received value 305419899
Received request read block 4
Thread 1 requested block 4 an received value 305419900
Thread 2 requested block 4 an received value 305419900
Waiting for handler thread to exit...
Handler thread has exited.
Operation took 4.303845920 seconds

### [Hints](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-26)

-   The system requires the addition of some shared state between the handler and client threads in order to pass the value from the handler to the requesting client.
-   A client needs to be able to block waiting on the handler to fullfil the request.
-   Based on the requested block, the handler needs to be able to identify and wake the client waiting for the specific result.
-   The is a limited number of concurrent outstanding requests allowed. `cdrom_block_request()` should not be called more than the `MAX_CONCURRENT_REQ` without the handler first resolving the request.

# [Deliverable 2: Video Overview](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-27)

**This is an assessable component of this assignment.**

The task in this section is to make a 1 to 2 minute video which overviews your solutions to the coding problems above.

We want you to show evidence that you have thought about the problems and convey the insights as to how your solution solves the problems.

Specifically, within your video, for each part of the assignment, you should:

> -   Clearly describe what are the concurrency problems.
> -   Clearly describe how your solution solves the concurrency problems identified.

The quality of the video is not going to be assessed; except that we must be able to clearly hear what you are saying, and be able to see any visuals you show.

# [Submitting](https://cgi.cse.unsw.edu.au/~cs3231/24T1/assignments/asst1/#toc-entry-28)

You are required to submit the two deliverables seperately.

> 1.  The coded solution to the problems.
> 2.  The video overview of your solution.

The submission instructions are available on the [Wiki](https://wiki.cse.unsw.edu.au/cs3231cgi/Setup/Submission) .
