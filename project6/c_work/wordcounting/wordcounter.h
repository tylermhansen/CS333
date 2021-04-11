/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
04/09/2021
*/

/* 
wordcounter.h: Declares the basic functions of the Word Counter object.
*/

#ifndef wordcounter
#define wordcounter

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct WordCounter {

    // File object
    FILE *fptr;
    // File path
    char path[100];

    // List of distinct words
    char words[MAX_WORDS][MAX_WORD_LENGTH];

    // Stores a single word
    char word[MAX_WORD_LENGTH];

    // Frequency of each distinct word
    int count[MAX_WORDS];

    // Number of distinct words
    int num_words;
    
} WordCounter;

struct kvp {
        int freq;
        char* word;
} kvp;

/*
 * Function:  wc_create 
 * --------------------
 * Creates a WordCounter in memory.
 * 
 * returns: the new WordCounter object.
 */
WordCounter *wc_create();

/*
 * Function:  wc_read 
 * --------------------
 * Count the number of words in the file and save to the instance variables.
 * 
 * parameters:
 * File f -- the file to count the words from.
 *
 * returns: N/A
 */
void wc_read(WordCounter *wc, char *path);

/*
 * Function:  wc_print
 * --------------------
 * Print the top 20 words in terms of the word frequency in descending order.
 *
 * returns: N/A
 */
void wc_print(WordCounter *wc);

#endif /* wordcounter */
