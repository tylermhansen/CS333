/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
05/08/2021
*/

/* 
timing_experiments.c -- Conducts a multi-threaded merge sort of N threads and times the process. Flexibility for maximum numbre of elements, threads, etc.
*/

#include "mergesortlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int main(int argc, char **argv){
    printf("%-15s\tTime\n", "Threads");
    clock_t start, end;
    float cpu_time_used;

    char *cp;
    struct tcp *tcp;

    int m = 512;

    int* a = malloc(sizeof(int) * m);

    // Generate random values for the array, store them in it.
    for (int i = 0; i < m; i++) {
        a[i] = rand() % 100;
    }

    for(int i = 1; i <= 512; i = i * 2){
        start = clock();
        driver(a, m, i, cp, tcp);
        end = clock();
        cpu_time_used = ((float) (end - start)) / CLOCKS_PER_SEC;
        printf("%-15d\t%f\n", i, cpu_time_used);
    }
}