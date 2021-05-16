/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
05/09/2021
*/

/* 
mergesort.h: Declares the functions of mergesort library.
*/

#ifndef mergesortlib
#define mergesortlib

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


// Define the maximum number of elements for the arrays used. 
int MAX;

// Define the maximum number of threads for the program.
int THREAD_MAX;

// array of size MAX
int *a;

// This struct holds essential **thread control parameters**. This is used to keeep track of the threads while conducting the merge sort. The most important is the POSIX thread id, which makes it so we don't 
// accidentally get any race conditions.
struct tcp {
    int tcp_id;
    int tcp_low;
    int tcp_high;
};

/*
 * Function:  merge 
 * --------------------
 * Merge two subarrays together into one new subarray given three indice. 
 * 
 * parameters:
 * int low -- The first index of the lower subarray. 
 * int mid -- The middle index of the new subarray (the last index of the lower subarray)
 * int high -- The last index of the higher subarray. 
 * 
 * returns: N/A
 */
void merge(int low, int mid, int high);

/*
 * Function:  merge _sort
 * --------------------
 * Perform a recursive merge sort on a given array. 
 * 
 * returns: N/A
 */
void merge_sort(int low, int high);

/*
 * Function:  merge_sort_thread
 * --------------------
 * Perform a recursive merge sort on a given subarray; for use with a specific POSIX thread, given by arg.
 * 
 * returns: N/A
 */
void *merge_sort_thread(void *arg);

/*
 * Function:  driver
 * --------------------
 * Just wraps the main function so that the behavior can be replicated, but not in a script-like manner. It's really so that I can keep the terminal input stuff but also
 * save time when running the timing experiment. Prints out times instead of anything else in a ready-to-CSV format.
 * 
 * returns: N/A
 */
void driver(int* a, int max, int thread_max,  char *cp, struct tcp *tcp);

// Main function
int driver_print(int argc, char **argv);



#endif /* mergesortlib */
