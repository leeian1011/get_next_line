# get_next_line

This 42 project introduces us to quite a few topics, mainly,
1. static variables
2. file descriptors
3. `read` system call.

## Things I've learnt

There were quite a handful of interesting stuff that I learnt from this project.

### Memory Segments
Static variables introduced me to memory layouts in binary, particularly about `bss` (uninitialized data region) and initialized data region memory segments.<br>
bss holds all the uninitialized static and global variables, and the compiler will assign the value of these 'uninitialized' data to 0.<br>
[There is this GeeksForGeeks article that does a quick rundown of this topic](https://www.geeksforgeeks.org/memory-layout-of-c-program/).

### File Descriptors
File descriptors(fd) used to have a hard and soft limit on how many fd(s) a process could have open at any one time, however, these limits
is still baked into our modern operating systems.<br>

In the past, the way operating systems handled processes were much different, each process would have a data structure pre-emptively pre-allocated,
depending on a `NOFILE` constant. This `NOFILE` constant represents the maximum number of files a process can have opened, and as such, it would affect
the size of the data structure allocated for the process.<br>

This data structure that is pre-allocated, takes up memory, and back in the old days, memory was hard to comeby and should be used sparringly.
This is one of the historical reasons why there is a soft and hard limit on fds as well as why we are able to tweak the limits on a per-process
basis.<br>

[Source](https://unix.stackexchange.com/questions/625616/what-is-the-historical-reason-for-limits-on-file-descriptors-ulimit-n)

### `read` system call
This is a system call that I work with a lot in my day job, and although I believed I was very familiar with it, it seems there is a 
little interesting snippet in the man pages for the `read` system call.<br>
```
"If count is zero, read() may detect the errors described below.
    In the absence of any errors, or if read() does not check for
        errors, a read() with a count of 0 returns zero and has no other
        effects."
```

This to me seems to imply that calling `read()` with a count of 0, could lead to non-deterministic results, such that
an error could've occured, but the return value of `read()` would still be 0 instead of -1.

## New approach to 42

Having completed this project a good 2 weeks ago prior to submitting it, I found that I struggle to remember the choices I made in the code 
as well as certain decisions that I made whilst writing it, I decided to change my approach to immediately evaluate after completion of project,
as I struggled to explain some of my code, even whilst reading it.
