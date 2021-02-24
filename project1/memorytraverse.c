/*
Project 1 Memory Traverse Program: A simple program in which variables are declared
and memory is accessed in sequence to explore the indices in which bytes are stored in memory.
Expected result is a segmentation fault.

Tyler Hansen
CS333 Spring 2021
02/24/2021 
*/

#include <stdio.h>
#include <stdlib.h>
        
/* 
Simply declares variables of different types and assigns a character the address
of itself and then the memory indices are iterated through.
*/ 
int main (int arg, char *argv[]) {

    short var_short = 32767;
    int var_int = 0x01234567;
    long var_long = 4242;
    float var_float = 4242.42;
    double var_double = 4242.4242;
    unsigned char *ptr;
    ptr = &ptr;

    for(int i=0; i >= 0; i++) {
	    printf("%d: %02X\n", i, ptr[i]);
    }			
      return 0;
}  