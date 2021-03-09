/* 
Tyler Hansenå
CS333 Spring 2021 -- Programming Languages
3/8/2021
*/

/* 
cstk.c: Describes the Stack data structure.
*/

#include "cstk.h"
int CSTK_MAX = 50;

/*
 * Function:  stk_create 
 * --------------------
 * Creates a stack in memory with the size specified by the int value
 *
 * int size: number of elements to contain in the stack. 
 *
 * returns: the new Stack object.
 */
Stack *stk_create(int size) 
{
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->top = size;
}

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
void stk_push(Stack *S, int n)
{
    if (S->top < CSTK_MAX)
        S->stack[S->top++] = n ;
    else
        fprintf(stderr, "Error: the stack object is full.\n");
}

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
int stk_pop(Stack *S)
{
    if (S->top == 0)
        fprintf(stderr, "Error: the stack object is empty.\n");
    else{
        int val = S->stack[S->top];
        S->top--;
        return val;
    }
}

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
void stk_display(Stack *S, int n)
{
if (n == 1) {
    for (int j = S->top; j >= 0; j--){
        printf("%d", S->stack[j]);
    }
    printf("\n");
} else {
    for (int i = 0; i < S->top; i++){
        printf("%d", S->stack[i]);
    }
    printf("\n");
}
}

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
void stk_destroy(Stack *S)
{
    free(S->stack);
    free(S->top);
    free(S);
}