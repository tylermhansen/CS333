/*
Project 1 strcpy Robustness Exploration: A simple program that passes a string
that is slightly too long to a local character array of fixed length.

Tyler Hansen
CS333 Spring 2021
02/24/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        
/* 
Creates a struct object with an odd number of bytes and investigates
its memory usage.
*/ 
int main (int arg, char *argv[]) {

    char the_answer_to_life_the_universe_and_everything[6]; // An array that can hold 7 characters.
    int decision = 0;
    strcpy(the_answer_to_life_the_universe_and_everything, "FortyTwo"); // Copy a string that is 8 characters long into array.
    if (decision == 0) {
        printf("Safe!");
    } else {
        printf("Hacked!");
    }

    return 0;

}  