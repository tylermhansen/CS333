/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
3/30/2021
*/

/* 
linked_list.c: Describes a linked list data structure.
*/

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Function:  ll_create 
 * --------------------
 * Creates a Linked List in memory
 *
 * returns: the new LinkedList object.
 */
LinkedList *ll_create(){
    LinkedList *list = malloc(sizeof(LinkedList)); 
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

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
void ll_push(LinkedList *l, void *data){
    Node* new_node = malloc(sizeof(Node)); // Allocate space for a new node
    new_node->val = data; // Set new node's data to input param
    // If list is empty, assign tail
    if(l->tail == NULL){
        l->tail = new_node;
    }
    // If list is not empty, make backwards link
    if(l->head != NULL){
        l->head->prev = new_node;
    }
    // Reassignment of head
    new_node->next = l->head;
    l->head = new_node;
    l->size += 1;
    return;
}

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
void *ll_pop(LinkedList *l){
    if (l->head == NULL){
        printf("Tried to pop empty list...\n");
        exit(-1);
    }
    Node *prev_head = l->head; // Save the current head
    void *return_data = prev_head->val;
    l->head = l->head->next; // Set the new head to the next node in the LinkedList.
    l->head->prev = NULL; // Set the new head's previous to null as it wouldn't be the head if it had a previous.
    l->size -= 1;
    free(prev_head);
    if(l->head == NULL){
        l->tail = NULL;
    }
    return return_data;
} 

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
void ll_append(LinkedList *l, void *data){
    Node* new_node = malloc(sizeof(Node));
    new_node->val = data;
    new_node->next = NULL;
    // If list is empty, assign head
    if(l->head == NULL){
        l->head = new_node;
    } 
    // If list is not empty, make forwards link
    if(l->tail != NULL){
        l->tail->next = new_node;
    }
    // Reassignment of tail
    new_node->prev = l->tail;
    l->tail = new_node;
    l->size += 1;
    return;
}

/*
 * Function:  ll_remove
 * --------------------
 * Removes the first node in the list whose data matches target given the comparison function. 
 * The function returns the pointer to the data.
 * 
 * LinkedList *l: the LinkedList we wish to remove an element from.
 * void *target: the target data. 
 * int *compfunc: the function that compares the target data to the data stored in the linked list and returns 1 if they are equal and 0 otherwise.
 *
 * returns: The pointer to the data if found, NULL otherwise.
 */
void *ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
    Node* n = l->head;
    // Null return for empty lists
    if (n == NULL){
        return n;
    }
    // Iterate through each node and check for match
    while (n != NULL && !compfunc(n->val, target)) {
        n = n->next;
    }
    // If not found in list, return null
    if (n == NULL){
        return NULL;
    }
    if (n->prev != NULL){
        // New head is not necessary
        n->prev->next = n->next;
    } else {
        // Reset head
        l->head = n->next;
    }
    if(n->next != NULL){
        // New tail is not necessary
        n->next->prev = n->prev;
    } else{
        // Reset tail
        l->tail = n->prev;
    }
    void * return_data = n->val;
    free(n);
    l->size -= 1;
    return return_data;
}

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
int ll_size(LinkedList *l){
    return l->size;
}

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
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    Node* n;
    while (l->head != NULL) {
        n = l->head;
        l->head = l->head->next;
        freefunc(n->val);
        free(n);
    }
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return;
}

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
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    Node* n = l->head; 
    while (n != NULL) {
       mapfunc(n->val);
       n = n->next;
    }
    return;
}