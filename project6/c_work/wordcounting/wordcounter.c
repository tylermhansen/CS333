/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
04/09/2021
*/

/* 
wordcounter.c: Describes a word counter object.
*/

#include "wordcounter.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
 * Function:  wc_create 
 * --------------------
 * Creates a WordCounter in memory.
 * 
 * returns: the new WordCounter object.
 */
WordCounter *wc_create(){
    WordCounter *counter = malloc(sizeof(WordCounter)); 
    return counter;
}

/*
 * Function:  wc_read 
 * --------------------
 * Count the number of words in the file and save to the instance variables of the wc object.
 * 
 * parameters:
 * WordCounter *wc -- the WordCounter object
 * String path -- the ptah to the file. 
 *
 * returns: N/A
 */
void wc_read(WordCounter *wc, char *path){
    // Try to open the file
    wc->fptr = fopen(path, "r");

    // Exit if the file was not opened successfully.
    if (wc->fptr == NULL)
    {
        printf("Unable to open file, check privileges and try again.\n");
        exit(-1);
    }

    // Reading logic control variables
    int i, len, index, isUnique;

    // Initialize frequency of each word to 0.
    for (i=0; i<MAX_WORDS; i++)
        wc->count[i] = 0;

    index = 0;
    
    while (fscanf(wc->fptr, "%s", wc->word) != EOF)
    {
       
        // Convert word to lowercase
        for(i = 0; i < strlen(wc->word); i++){
            wc->word[i] = tolower(wc->word[i]);
        }

        // Remove last punctuation character
        len = strlen(wc->word);
        if (ispunct(wc->word[len - 1])){
            wc->word[len - 1] = '\0';
        }

        // Check if the word exists already in list of unique words
        isUnique = 1;
        for (i=0; i<index && isUnique; i++)
        {
            if (strcmp(wc->words[i], wc->word) == 0){
                isUnique = 0;
            }   
        }

        // If word is indeed unique, then add it to distinct words list
        // and increment index control variable. Otherwise, increment frequency 
        // count of current word.
        if (isUnique) 
        {
            printf("found unique word %s \n", wc->word);
            strcpy(wc->words[index], wc->word);
            wc->count[index]++;
            wc->num_words++;
            index++;
        }
        else
        {
            wc->count[i - 1]++;
        }
    }
}

/*
 * Function:  swap_strings
 * --------------------
 * Swap two strings when using character pointers. 
 *
 * parameters: 
 * char **str1_ptr: String 1 
 * char **str2_ptr: String 2
 */
void swap_strings(char **str1_ptr, char **str2_ptr)
{
  char *temp = *str1_ptr;
  *str1_ptr = *str2_ptr;
  *str2_ptr = temp;
}  
   

/*
 * Function:  wc_sort_descending
 * --------------------
 * Sort the words in the word counter object by their frequency in descending order.
 *
 * parameters: 
 * WordCounter *wc -- the WordCounter object storing the words in question
 */
void wc_sort_descending(WordCounter *wc){
    for (int i = 0; i < wc->num_words; ++i) 
        {
            for (int j = i + 1; j < wc->num_words; ++j) 
            {
                if (wc->count[i] < wc->count[j]) 
                {
                    int temp_count = wc->count[i];
                    wc->count[i] = wc->count[j];
                    wc->count[j] = temp_count;

                    swap_strings(wc->words[i], wc->words[j]);
                    
                }
            }
        }
}


/*
 * Function:  wc_print
 * --------------------
 * Print the top 20 words in terms of the word frequency in descending order.
 *
 * returns: N/A
 */
void wc_print(WordCounter *wc){

    wc_sort_descending(wc);

    for (int i=0; i<20; i++)
    {
        /*
         * %-15s prints string in 15 character width.
         * - is used to print string left align inside
         * 15 character width space.
         */
         // printf("%-15s => %d\n", data[i].word, data[i].freq);
        printf("%-15s => %d\n", wc->words[i], wc->count[i]);
    }    
}


