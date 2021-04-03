/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/30/2021
*/

/* 
linkedlist.h: Declares the basic functions of the Linked List data structure.
*/

#ifndef linkedlist
#define linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void * val;
    struct Node * prev;
    struct Node * next;
} Node;

typedef struct LinkedList { 
    int size; 
    Node *head;
    Node *tail; 
} LinkedList;

/*
 * Function:  ll_create 
 * --------------------
 * Creates a Linked List in memory.
 *
 * returns: the new LinkedList object.
 */
LinkedList *ll_create();

/*
 * Function:  ll_push 
 * --------------------
 * Adds a node to the front of the list, storing the given data in the node.
 * 
 * LinkedList *l: the LinkedList to add a node to the front of. 
 * void *data: data stored in the node to add to the LinkedList.
 *
 * returns: N/A
 */
void ll_push(LinkedList *l, void *data); 

/*
 * Function:  ll_pop 
 * --------------------
 * Removes the node at the front of the list and returns the associated data.
 * 
 * LinkedList *l: the LinkedList to remove the first value of. 
 *
 * returns: 
 * data: the data stored in the first node.
 */
void *ll_pop(LinkedList *l); 

/*
 * Function:  ll_append 
 * --------------------
 * Adds a node to the end of the list, storing the given data in the node.
 * 
 * LinkedList *l: the LinkedList to add a node to the front of. 
 * void *data: data stored in the node to add to the LinkedList.
 *
 * returns: N/A
 */
void ll_append(LinkedList *l, void *data);

/*
 * Function:  ll_remove
 * --------------------
 * Removes the first node in the list whose data matches target given the comparison function. 
 * The function returns the pointer to the data.
 * 
 * LinkedList *l: the LinkedList we wish to remove an element from.
 * void *target: the target data. 
 * int *compfunc: the function that compares the target data to the data stored in the linked list and returns a pointer to the data.
 *
 * returns: N/A
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)); 

/*
 * Function:  ll_size
 * --------------------
 * Returns the size of the LinkedList
 * 
 * LinkedList *l: the LinkedList we wish to get the size of.
 *
 * returns: 
 * int size: the number of elements in the LinkedList. 
 */
int ll_size(LinkedList *l);

/*
 * Function:  ll_clear
 * --------------------
 * Removes all of the nodes from the list, freeing the associated data using the given function.
 * 
 * LinkedList *l: the LinkedList we wish to clear.
 * *freefunc: the function to free the memory.
 *
 * returns:  N/A
 */
void ll_clear(LinkedList *l, void (*freefunc)(void *));

/*
 * Function:  ll_map
 * --------------------
 * Traverses the list and applies the given function to the data at each node.
 * 
 * LinkedList *l: the LinkedList we wish to clear.
 * *mapfunc: the function to apply to the data at each node.
 *
 * returns:  N/A
 */
void ll_map(LinkedList *l, void (*mapfunc)(void *)); 

#endif /* linkedlist */

