/*
Project 1 Struct Memory Allocation: A simple program that creates a struct object
with an odd number of bytes. 

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

    struct ChessBoard {
        /*
        Describes a rudimentary ChessBoard object. What opening is played,
        which side the board is viewed from and the number of pawns left
        on the board for that side.
        */
        char opening[23];
        char side; // B or W
        short num_pawns;
    };

    struct ChessBoard CarlsenNakamura;
    strcpy(CarlsenNakamura.opening, "Italian");
    CarlsenNakamura.side = 'W';
    CarlsenNakamura.num_pawns = 8;

    unsigned char *ptr;
    ptr = (unsigned char *)&(CarlsenNakamura);

    // Print out the memory allocated for the CarlsenNakamura object.
    for(int i=0; i<sizeof(CarlsenNakamura); i++) {
        printf("%d: %02X\n", i, ptr[i]);
    }

    printf("Size of CarlsenNakamura is %d", sizeof(CarlsenNakamura));

    return 0;

}  