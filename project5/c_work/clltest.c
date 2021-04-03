/*
	Bruce Maxwell
	Fall 2012
	CS 333

	Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

// function that prints an integer
void printInt(void *i) {
	int *a = (int *)i;

	printf("value: %d\n", *a);
}

// function that squares an integer
void squareInt(void *i) {
	int *a = (int *)i;

	*a = *a * *a;
}

// function that compares two integers and returns 1 if they are equal
int compInt(void *i, void *j) {
	int *a = (int *)i;
	int *b = (int *)j;

	return(*a == *b);
}

// test function for the various linked list functions
int main(int argc, char *argv[]) {
	LinkedList *l;
	int *a;
	int *target;
	int i;

	printf("This happens when main is called...\n");

	// create a list
	l = ll_create();

	printf("This is after ll_create happens...\n");


	// push data on the list
	for(i=0;i<20;i+=2) {
		a = malloc(sizeof(int));
		*a = i;

		ll_push(l, a);
	}

	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printInt);

	ll_map(l, squareInt);

	printf("\nAfter squaring\n");
	ll_map(l, printInt);

	// testing removing data
	target = malloc(sizeof(int));

	*target = 16;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	*target = 11;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	printf("\nAfter removals\n");
	ll_map(l, printInt);

	// testing appending data
	ll_append(l, target);

	printf("\nAfter append\n");
	ll_map(l, printInt);

	// test clearing
	ll_clear(l, free);

	printf("\nAfter clear\n");
	ll_map(l, printInt);

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		a = malloc(sizeof(int));
		*a = i;
		ll_append(l, a);
	}

	printf("\nAfter appending\n");
	ll_map(l, printInt);

	a = ll_pop(l);
	printf("\npopped: %d\n", *a);
	free(a);

	a = ll_pop(l);
	printf("popped: %d\n", *a);
	free(a);

	printf("\nAfter popping\n");
	ll_map(l, printInt);

	printf("\nList size: %d\n", ll_size(l) );

	return(0);
}