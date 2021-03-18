/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/13/2021
*/

/* 
quicksort.c: Given an array of random integers, sort it in such a way that the even 
numbers appear first and the odd numbers appear later. The even numbers 
should be sorted in descending order and the odd numbers should be sorted 
in ascending order.
*/


/*
Adapted from code written by Ying Li on 08/02/2016
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * Function: comparator
 * --------------------
 * Returns where the element p and element q should be placed with respect to one another in the array to 
 * satisfy the sorting rules outlined above. 
 * 
 * Parameters:
 * const void *p: Left element pointer
 * const void *q: Right element pointer
 *
 * Returns: -1 if l goes first, 1 if r goes first. 
 */
int comparator (const void *p, const void *q) {

	// Get the values at the given element addresses 
    int l = *(const int *)p; 
    int r = *(const int *)q; 

	/* 
	Note that I am using bitwise AND here. k & 1 does a bitwise AND operation of the k variable and the 1 literal. 
	The expression results in either 0 (if the least significant bit of k is 0) or 1 (if the least significant bit of k is 1). 
	This is functionally the same as doing k % 2 and getting 0 or 1. 
	Since the expression is the condition for the if statement, it is implicitly cast to bool, 
	for which 1 maps to true and 0 maps to false.
	*/ 

    // If both are odd, put the lesser of two first. 
    if ((l & 1) && (r & 1)) 
        return (l - r); 
  
    // If both are even, put the greater of two first.
    if (!(l & 1) && !(r & 1)) 
        return (r - l); 
  
    // If only l is even, put l first.
    if (!(l & 1)) 
        return -1; 
  
    // If only l is odd, put r first.
    return 1; 
}

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}