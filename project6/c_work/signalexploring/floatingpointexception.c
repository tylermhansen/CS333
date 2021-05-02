/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
04/30/2021
*/

/* 
timepercall.c: Explores the time that it takes (on average) to allocate a certain amount of memory.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function calculates the average time to allocate different ammounts of memory and prints these to the console.
int main()
{
    // Define variables average, start, end, and cpu_time_used for use with time.h
    float average = 0.0;
    clock_t start, end;
    double cpu_time_used;

    // Loop through a ton of different malloc times
    for(int i = 16; i < 0x100000; i = i * 2){
        start = clock();
        double *vect = malloc(i);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("%f", cpu_time_used);
    }


    return 0;
}