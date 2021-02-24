/*
Project 1 Bus Error Generation: A simple program that generates a bus error.

Tyler Hansen
CS333 Spring 2021
02/24/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

/*
Simply generates a bus error. I tried using an unaligned memory access,
but that won't work on x86 machines. This is the best solution I could find
in my research. 

From mmap documentation: (https://pubs.opengroup.org/onlinepubs/000095399/functions/mmap.html) 
References within the address range starting at pa and continuing for len bytes 
to whole pages following the end of an object shall result in delivery of a SIGBUS 
signal.
*/
int main(int argc, char **argv) 
{
    FILE *f = tmpfile();
    int *x = mmap(0, 4, PROT_WRITE, MAP_PRIVATE, fileno(f), 0);
    *x = 0;
    return 0;
}