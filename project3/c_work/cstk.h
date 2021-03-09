/* 
Tyler Hansenå
CS333 Spring 2021 -- Programming Languages
3/8/2021
*/

/* 
cstk.h: Declares the basic functions of the Stack data structure.
*/
#ifndef cstk
#define cstk

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
    int  *stack;
    int  top;
}  Stack;

/*
 * Function:  stk_create 
 * --------------------
 * Creates a stack in memory with the size specified by the int value
 *
 * int size: number of elements to contain in the stack. 
 *
 * returns: the new Stack object.
 */
Stack *stk_create(int size); 

/*
 * Function:  stk_push 
 * --------------------
 * Adds a new value to the top of the stack.
 * 
 * Stack* S: the stack to add a value to. 
 * int d: value to add to the stack.
 *
 * returns: N/A
 */
void stk_push(Stack *S, int n); 

/*
 * Function:  stk_pop 
 * --------------------
 * Removes a value from the top of the stack.
 * 
 * Stack* S: the stack to remove a value from.
 *
 * returns: 
 * int val: the integer that was at thee top of the stack.
 */
int stk_pop(Stack *S); 

/*
 * Function:  stk_display 
 * --------------------
 * Prints out the list in the reverse order if the int value is 1, otherwise, prints out in the original order
 * 
 * Stack* S: the stack to print.
 * int n: order decider.
 *
 * returns:     
 * N/A
 */
void stk_display(Stack *S, int n); 

/*
 * Function:  
 * --------------------
 * Recycles the stack.
 * 
 * Stack* S: the stack to recycle.
 *
 * returns:     
 *  N/A
 */
void stk_destroy(Stack *S); 

#endif /* cstk */