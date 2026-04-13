*This project has been created as part
of the 42 curriculum by tmalpert*

# Codexion
## Description
### Project Overview

Codexion is a **multithreading** project whose goal is to simulate the simultaneous execution of multiple “coders” working on different tasks (compiling, debugging, refactoring).<br>
To compile, each coder must acquire two dongles and hold them for the entire compilation phase. These dongles are shared between coders in such a way that each coder shares their two dongles with their neighbors.<br>
Each coder is represented by a **thread**, allowing us to reproduce a concurrent environment where multiple actions occur in parallel.<br>
This project demonstrates fundamental concepts of **concurrent programming** in C, using the ```pthread``` library.

#### Here is a more detailed explanation of the project based on the topic:

>Here are the things you need to know if you want to succeed in this assignment:
> - One or more coders sit in a circular inclusive co-working hub.
>In the center, there is a shared Quantum Compiler.
> - The coders alternatively compile, debug, or refactor.
>While compiling, they are not debugging nor refactoring;
>while debugging, they are not compiling nor refactoring;
>and, of course, while refactoring, they are not compiling nor debugging.
> - There are USB dongles on the table. There are as many dongles as coders.
> - Compiling quantum code requires two dongles plugged in simultaneously,
>one in each hand: a coder takes their left and right dongles to compile.
> - When a coder finishes compiling, they put both dongles back on the table and start
>debugging.
>Once debugging is done, they start refactoring. The simulation stops when a coder
>burns out due to lack of compiling.
> - Every coder needs to compile regularly and should never burn out.
> - Coders do not communicate with each other.
> - Coders do not know if another coder is about to burn out.
> - Needless to say, coders should avoid burnout!

### What is Multithreading?

Multithreading consists of executing multiple parts of a program at the same time.
Unlike a classic (sequential) program:

```
Task 1 → Task 2 → Task 3
```

With threads:
```
Task 1
Task 2   → executed in parallel
Task 3
```
Each thread has:
- its own execution flow
- but shares the same memory space

### What is a thread? 

A thread is a sub-part of a process, i.e., an execution unit within a program.
A process is a program in execution.
The CPU, composed of multiple cores, executes processes and their threads by distributing and switching between them across cores.
Common Multithreading Issues
<br>
<br>

If not handled properly, multithreading can lead to:
- **Race Conditions**: <br>
A race condition occurs when multiple threads access and modify the same data simultaneously without proper synchronization.
Result: unpredictable behavior and hard-to-reproduce bugs.

- **Deadlocks**: <br>
A deadlock occurs when two (or more) threads are waiting for resources held by each other.
Result: the program becomes completely stuck.

Of course, there are many other mistakes, but these two are the most common.

### UML

Below is a simplified diagram of the program execution:

```mermaid
flowchart TD
subgraph MAIN
B[Parsing]
B --> C[Init simulation]
C --> D[Start threads]
D --> X[Join threads]
X --> Y[Clean simulation]
end

%% CODERS
subgraph CODERS
H1{Simulation is finished?}
H2{Simulation is finished?}
H3{Simulation is finished?}

I{Has the coder completed required compilations?}

Z[Stop thread]

J{dongles are avaible}
K[take dongles]
L[compile] --> H2
M[debug] --> H3
N[refactor] --> I
O[release dongles]

J --> |no| J
J --> |yes| K

H2 --- O
H1 --> |yes| Z
H3 --> |yes| Z
H1 --> |no| L
H3 --> |no| N

O --> |no| M
O --> |yes| Z
end

%% MONITOR
subgraph MONITOR
D --> R{Is burnout?}
R --> S{Is finish?}
R -->|yes| T[end of simulation]
S -->|no| R
R -->|no| R
S -->|yes| T
end

%% STYLES
classDef main fill:#1e1e2f,color:#fff,stroke:#ffffff
classDef process fill:#3b82f6,color:#fff,stroke:#1e3a8a
classDef decision fill:#f59e0b,color:#fff,stroke:#92400e
classDef alert fill:#ef4444,color:#fff,stroke:#7f1d1d
class A main
class B,C,D,E,F,G,K,L,M,N,O,P,Q,T,X,Y process
class H1,H2,H3,I,J,R,S decision

class Z alert

D --> I
K --> H1
I --> J
```
## Instructions

To use the project:

**1/ Clone the repository:**
```
git clone <repository_url>
```
**2/ Build the project:**
```
make
or
make all
```

Available Makefile commands:

- ```make clean``` → remove object (.o) and dependency (.d) files
- ```make fclean``` → remove object, dependency files and the executable
- ```make re``` → full rebuild (fclean + all)

**3/ Usage**

After building, an executable named ```codexion``` will be created.

Run it with the following arguments:

```shell
./codexion number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```
Example:
```shell
./codexion 10 200 10 10 10 5 10 edf
```
Output Format
```
<time_from_start_in_ms> <coder_id> <action>
```
## Resources
### Allowed Functions:
 - pthread_create
 - pthread_join
 - pthread_mutex_init
 - pthread_mutex_lock
 - pthread_mutex_unlock
 - gettimeofday
 - usleep
 - malloc
 - free
 - printf
 - fprintf
 - strcmp
 - atoi

### online resource:
- IA 
- [man](https://man7.org/linux/man-pages/index.html)<br>
- [How to use pthread](https://perso.ens-lyon.fr/francois.schwarzentruber/teaching/l3-prog/book/c_thread.html)


>## Disclaimer
> 1/ During this project, I used AI tools primarily to help me understand multithreading functions, as well as to translate and edit certain sections of the README. 
> 
> 2/ This project was carried out as part of the core curriculum at 42 school. It is not intended to be perfect, but rather to illustrate my level and progress at this stage of my journey at 42 school.