/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
05/01/2021
*/

/* 
numberoftimes.c: Explores the time that it takes (on average) to allocate a certain amount of memory over time to see if the time of a memory management call changes with the number of allocation and free operations the program has executed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Main function calculates the average time to allocate a certain amount of memory after a certain amount of calls.
int main(int argc, char *argv[])
{
    long input_size;
    // Capture command line input. 
    if( argc == 2 ) {
        input_size = atol(argv[1]); 
    } else if( argc > 2 ) {
        printf("Too many arguments supplied.\n");
        exit(-1);
    } else {
        printf("Please enter the size of the malloc in bytes.\n");
        exit(-1);
    }

    // Define variables average, start, end, and cpu_time_used for use with time.h
    float average = 0.0;
    clock_t start, end;
    float cpu_time_used_m, cpu_time_used_f;

    printf("%-15s \tmalloc_time\n", "num_calls_prev");
    start = clock();
    
    // COnduct 500000 malloc calls. Every 10000, calculate and record how much time it took. 
    for(int i = 1; i <= 500000; i = i + 1){
        if(i % 10000 == 0){
            end = clock();
            cpu_time_used_m = ((float) (end - start)) / (CLOCKS_PER_SEC);
            printf("%-10d \t %f \n", i, cpu_time_used_m);
            start = clock();
        }
        double *vect = malloc(input_size);
        free(vect);
    }

    return 0;
}