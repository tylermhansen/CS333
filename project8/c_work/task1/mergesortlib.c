/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
05/08/2021
*/

/* 
mergesort.c -- Conducts a multi-threaded merge sort of N threads and times the process. Flexibility for maximum numbre of elements, threads, etc.
*/

#include "mergesortlib.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


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
void merge(int low, int mid, int high){

    // Note that size1 is size of left subarray and size2 is size of right subarray.
    int size1 = mid - low + 1;
    int size2 = high - mid;

    // Allocate space for the left and right subarrays. 
    int *left = malloc(size1 * sizeof(int));
    int *right = malloc(size2 * sizeof(int));

    int i;
    int j;

    // Store values in left part
    for (i = 0; i < size1; i++)
        left[i] = a[i + low];

    // Store values in right part
    for (i = 0; i < size2; i++)
        right[i] = a[i + mid + 1];

    int k = low;

    i = j = 0;

    // Merge the left and right subarrays in ascending order
    while (i < size1 && j < size2) {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    // insert remaining values from left
    while (i < size1)
        a[k++] = left[i++];

    // insert remaining values from right
    while (j < size2)
        a[k++] = right[j++];

    free(left);
    free(right);
}

/*
 * Function:  merge _sort
 * --------------------
 * Perform a recursive merge sort on a given array. 
 * 
 * returns: N/A
 */
void merge_sort(int low, int high){

    // Compute the mid point of the array.
    int mid = low + (high - low) / 2;

    // This conditional catches edge cases (ex. a length 1 array).
    if (low < high) {
        // Recursively call merge sort on the first half...
        merge_sort(low, mid);

        // then the second half...
        merge_sort(mid + 1, high);

        // ... then merge the two halves! 
        merge(low, mid, high);
    }
}

/*
 * Function:  merge_sort_thread
 * --------------------
 * Perform a recursive merge sort on a given subarray; for use with a specific POSIX thread, given by arg.
 * 
 * returns: N/A
 */
void *merge_sort_thread(void *arg){
    struct tcp *tcp = arg;
    int low;
    int high;

    // Get low and high for the given thread that is passed in by arg.
    low = tcp->tcp_low;
    high = tcp->tcp_high;

    // Compute the midpoint of the array.
    int mid = low + (high - low) / 2;

    // This conditional catches edge cases (ex. a length 1 array).
    if (low < high) {

        // Recursively call merge sort on the first half...
        merge_sort(low, mid);

        // then the second half...
        merge_sort(mid + 1, high);

        // ... then merge the two halves! 
        merge(low, mid, high);
    }
    return 0;
}

/*
 * Function:  driver
 * --------------------
 * Just wraps the main function so that the behavior can be replicated, but not in a script-like manner. It's really so that I can keep the terminal input stuff but also
 * save time when running the timing experiment. Prints out times instead of anything else in a ready-to-CSV format.
 * 
 * returns: N/A
 */
void driver(int* arr, int max, int thread_max,  char *cp, struct tcp *tcp){

    MAX = max;
    THREAD_MAX = thread_max;

    a = arr;
    // Initialize an array of threads and associated thread control parameter structs. 
    pthread_t threads[THREAD_MAX];
    struct tcp tcplist[THREAD_MAX];

    // Get the proper length of subarray.
    int len = MAX / THREAD_MAX;

    int low = 0;

    // Partition the subarrays out, assign proper thread control parameters to the list of them.
    for (int i = 0; i < THREAD_MAX; i++, low += len) {
        tcp = &tcplist[i];
        tcp->tcp_id = i;

        tcp->tcp_low = low;
        tcp->tcp_high = low + len - 1;
        if (i == (THREAD_MAX - 1)){
            tcp->tcp_high = MAX - 1;
        }
    }

    // Create THREAD_MAX threads and run the merge sort for each thread
    for (int i = 0; i < THREAD_MAX; i++) {
        tcp = &tcplist[i];
        pthread_create(&threads[i], NULL, merge_sort_thread, tcp);
    }

    // Join all the created threads.
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);


    // Merge together each subarrray associated with a thread.
    struct tcp *tcpm = &tcplist[0];
    for (int i = 1; i < THREAD_MAX; i++) {
        struct tcp *tcp = &tcplist[i];
        merge(tcpm->tcp_low, tcp->tcp_low - 1, tcp->tcp_high);
    }
}

// Main function
int driver_print(int argc, char **argv){
    char *cp;
    struct tcp *tcp;

    if(argc != 3){
        printf("Please supply length of array and number of threads. Ex ./mergetest 15 5\n");
        exit(-1);
    }

    MAX = atoi(argv[1]);
    THREAD_MAX = atoi(argv[2]);


    // Allocate the array for use with the merge sort.
    a = malloc(sizeof(int) * MAX);

    // Generate random values for the array, store them in it, and print out the original array to the termrinal.
    printf("ORIGINAL ARRAY:");
    for (int i = 0; i < MAX; i++) {
        a[i] = rand() % 100;
        printf(" %d", a[i]);
    }
    printf("\n");

    // Initialize an array of threads and associated thread control parameter structs. 
    pthread_t threads[THREAD_MAX];
    struct tcp tcplist[THREAD_MAX];

    // Get the proper length of subarray.
    int len = MAX / THREAD_MAX;

    // Print out the number of threads, the number of elements in the array, and the length of each subarray.
    printf("\nTHREADS:%d ARR SIZE:%d LEN:%d\n", THREAD_MAX, MAX, len);

    int low = 0;

    // Partition the subarrays out, assign proper thread control parameters to the list of them.
    for (int i = 0; i < THREAD_MAX; i++, low += len) {
        tcp = &tcplist[i];
        tcp->tcp_id = i;

        tcp->tcp_low = low;
        tcp->tcp_high = low + len - 1;
        if (i == (THREAD_MAX - 1)){
            tcp->tcp_high = MAX - 1;
        }
    }

    printf("\n");

    // Create THREAD_MAX threads and run the merge sort for each thread
    for (int i = 0; i < THREAD_MAX; i++) {
        tcp = &tcplist[i];
        pthread_create(&threads[i], NULL, merge_sort_thread, tcp);
    }

    // Join all the created threads.
    for (int i = 0; i < THREAD_MAX; i++)
        pthread_join(threads[i], NULL);

    // Print out the array value for each thread.
    for (int i = 0; i < THREAD_MAX; i++) {
        tcp = &tcplist[i];
        printf("SORTED SUBARRAY %d:", tcp->tcp_id);
        for (int j = tcp->tcp_low; j <= tcp->tcp_high; ++j)
            printf(" %d", a[j]);
        printf("\n");
    }
    // Merge together each subarrray associated with a thread.
    struct tcp *tcpm = &tcplist[0];
    for (int i = 1; i < THREAD_MAX; i++) {
        struct tcp *tcp = &tcplist[i];
        merge(tcpm->tcp_low, tcp->tcp_low - 1, tcp->tcp_high);
    }
    // Display the sorted array.
    printf("\nSORTED ARRAY:");
    for (int i = 0; i < MAX; i++)
        printf(" %d", a[i]);
    printf("\n");

    return 0;
}