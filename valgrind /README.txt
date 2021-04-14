2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ g++ test.cc
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ls -l a.out
-rwxr-xr-x@ 1 changliu  staff  19924 Apr  6 17:55 a.out
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ./a.out
55
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ g++ test1.cc
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ls -l a.out
-rwxr-xr-x@ 1 changliu  staff  15244 Apr  6 17:56 a.out
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ./a.out
Oops this didn't work
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ g++ test2.cc
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ./a.out
Segmentation fault: 11
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ g++ test3.cc
test3.cc:12:1: warning: control reaches end of non-void function [-Wreturn-type]
}
^
1 warning generated.
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ ./a.out
This worked
32767
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$

==============================================================================



To use valgrind, it's best to use "g++ -g -O2 test.cc" to compile the code.

2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ g++ -g -O2 test.cc
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ valgrind a.out
valgrind: a.out: command not found
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ valgrind ./a.out
==53656== Memcheck, a memory error detector
==53656== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==53656== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==53656== Command: ./a.out
==53656==
==53656== Invalid write of size 4
==53656==    at 0x100000B8F: main (test.cc:25)
==53656==  Address 0x100a8bf38 is 0 bytes after a block of size 40 alloc'd
==53656==    at 0x100007EA1: malloc (vg_replace_malloc.c:303)
==53656==    by 0x10004E7DD: operator new(unsigned long) (in /usr/lib/libc++.1.dylib)
==53656==    by 0x100000D6D: std::__1::vector<int, std::__1::allocator<int> >::__append(unsigned long) (new:168)
==53656==    by 0x100000B67: main (vector:1994)
==53656==
0
==53656==
==53656== HEAP SUMMARY:
==53656==     in use at exit: 26,288 bytes in 187 blocks
==53656==   total heap usage: 254 allocs, 67 frees, 32,128 bytes allocated
==53656==
==53656== LEAK SUMMARY:
==53656==    definitely lost: 0 bytes in 0 blocks
==53656==    indirectly lost: 0 bytes in 0 blocks
==53656==      possibly lost: 0 bytes in 0 blocks
==53656==    still reachable: 4,096 bytes in 1 blocks
==53656==         suppressed: 22,192 bytes in 186 blocks
==53656== Rerun with --leak-check=full to see details of leaked memory
==53656==
==53656== For counts of detected and suppressed errors, rerun with: -v
==53656== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$


==============================================================================
On Linux, glibc warns about this in runtime.

liu@tesla1:~/valgrind$ g++ -g -O2 test.cc
liu@tesla1:~/valgrind$ a.out
a.out: command not found
liu@tesla1:~/valgrind$ ./a.out
55
*** glibc detected *** ./a.out: free(): invalid next size (fast): 0x0000000000bd0c20 ***
a.out: malloc.c:2451: sYSMALLOc: Assertion `(old_top == (((mbinptr) (((char *) &((av)->bins[((1) - 1) * 2])) - __builtin_offsetof (struct malloc_chunk, fd)))) && old_size == 0) || ((unsigned long) (old_size) >= (unsigned long)((((__builtin_offsetof (struct malloc_chunk, fd_nextsize))+((2 * (sizeof(size_t))) - 1)) & ~((2 * (sizeof(size_t))) - 1))) && ((old_top)->size & 0x1) && ((unsigned long)old_end & pagemask) == 0)' failed.
Aborted (core dumped)
liu@tesla1:~/valgrind$

==============================================================================


2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ diff test3.cc test3a.cc
7a8
>
9a11
>     return false;
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$ diff test4.cc test4a.cc
13c13,14
<     sum+=i;
---
>     #pragma omp critical
>        sum+=i;
2012-MacBook-Pro-15-Retina:Valgrind.Coding changliu$
