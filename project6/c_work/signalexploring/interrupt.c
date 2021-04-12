/* 
Tyler Hansen
CS333 Spring 2021 -- Programming Languages
04/09/2021
*/

/* 
interrupt.c: Demonstrates user-handled interrupt (ctrl-c) signal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */
#define SIGFPE  7   /* Floating Point Exception */
  
// Handler for SIGINT, caused by Ctrl-C on keyboard
void handle_sigint(int sig){
    printf("\nCaught Interrupt signal. Program interrupted.\n");
    exit(0);
}

int main()
{
    // Infinite loop, break with keyboard interrupt
    signal(SIGINT, handle_sigint);
    while (1) ;
    return 0;
}