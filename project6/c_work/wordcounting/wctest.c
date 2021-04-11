/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
04/10/2021
*/

/* 
wctest.c: Tests the WordCounter object. 
*/

#include <stdio.h>
#include <stdlib.h>
#include "wordcounter.h"

int main(int argc, char *argv[]){
    WordCounter *wc;

    printf("This happens when main is called...\n");

	// create a WordCounter
	wc = wc_create();

	printf("This is after wc_create happens...\n");

    wc_read(wc, argv[1]);

    printf("This is after wc_read happens...\n");

    wc_print(wc);
}