/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/14/2021
*/

/* 
factorial.c: Given an integer from the command line, computes that integers' factorial.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Function: factorial_recursive
 * --------------------
 * Recursively returns the factorial of a given integer. 
 * 
 * Parameters:
 * int n: the integer to compute the factorial of.
 *
 * Returns: the factorial of n.
 */
int factorial_recursive(int n){
    if (n == 0) 
        return 1; 
    return (n * factorial_recursive(n - 1)); 
}

/*
 * Extension!
 * Function: factorial_iterative
 * --------------------
 * Iteratively returns the factorial of a given integer. 
 * 
 * Parameters:
 * int n: the integer to compute the factorial of.
 *
 * Returns: the factorial of n.
 */
int factorial_iterative(int n) 
{ 
    int result = 1, i; 
    for (i = 2; i <= n; i++) 
        result *= i; 
    return result; 
} 

// Main function
int main (int argc, char **argv) {
    
    // Using time.h, we will time the functions.
    clock_t start, end;
    double cpu_time_used;

    // Assign the factorial functions to calc variables
	int (*calc)(const int);
    calc = &factorial_recursive;
    int (*calc2)(const int);
    calc2 = &factorial_iterative;

    // Run and time the recursive implementation
    start = clock();
    int result = (*calc)(strtol(argv[1], NULL, 10)); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The factorial is %d and to compute it recursively took %f seconds. \n", result, cpu_time_used);

    // Run and time the iterative implementation
    start = clock();
    int result2 = (*calc2)(strtol(argv[1], NULL, 10)); 
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The factorial is %d and to compute it iteratively took %f seconds. \n", result2, cpu_time_used);

	return 0;
}
