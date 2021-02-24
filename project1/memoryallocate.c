/*
Project 1 Memory Allocate Program: A simple program that repeatedly allocates a small amount 
of memory in a loop that goes on for a long time. Just use a single variable to point to the memory 
(this is very bad, but it makes a good example). Using the terminal command top 
(or, if you are on a Mac, you can use the Activity Monitor), watch the memory requirements for your program grow.

Tyler Hansen
CS333 Spring 2021
02/24/2021 
*/

#include <stdio.h>
#include <stdlib.h>
        
/* 
Repeatedly allocates a small amount of memory in a loop that goes on forever (make sure to kill the process; this is purely
for examination purpoes using activity monitor / task manager / top / etc.).
Uses a single variable to point to the memory.
*/ 
int main (int arg, char *argv[]) {

    int *b;

    for (int i = 0; i >= 0; i++) {
        b = (int *)malloc(5 * sizeof(int));
        // free(b); // Toggle for investigation.
    }
    return 0;

}  