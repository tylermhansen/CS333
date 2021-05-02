/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
05/01/2021
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
    float cpu_time_used_m, cpu_time_used_f;

    printf("%-15s \tmalloc_time\tfree_time\n", "Bytes");
    // Loop through a ton of different malloc sizes and print them to the console.
    for(int i = 1; i < 0x10000000; i = i * 2){
        double *vect;
        start = clock();
        for(int j = 0; j < 400000; j++){
            vect = malloc(i);
        }
        end = clock();
        cpu_time_used_m = ((float) (end - start)) / (CLOCKS_PER_SEC * 400000);
        printf("%-15d \t %f \t", i, cpu_time_used_m);
        start = clock();
        free(vect);
        end = clock();
        cpu_time_used_f = ((float) (end - start)) / CLOCKS_PER_SEC;
        printf("%f\n", cpu_time_used_f);
    }

    return 0;
}