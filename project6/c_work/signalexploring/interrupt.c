// CPP program to illustrate
// User-defined Signal Handler
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
  
// Handler for SIGINT, caused by
// Ctrl-C at keyboard
void handle_sigint(int sig){
    printf("\nCaught Interrupt signal. Program interrupted.\n");
    exit(0);
}

int main()
{
    signal(SIGINT, handle_sigint);
    while (1) ;
    return 0;
}