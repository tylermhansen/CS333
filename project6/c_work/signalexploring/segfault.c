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
#define SIGFPE  8   /* Floating Point Exception */
#define SIGSEGV 11  /* Segmentation Fault */
  
// Handler for SIGSEGV, caused by a segmentation fault.
void handle_sigsegv(int sig){
    printf("\nCaught Segmentation Fault signal. Exiting...\n");
    exit(0);
}

int main()
{
    signal(SIGSEGV, handle_sigsegv);
    printf("Heading to create some undefined behavior...\n");
    *(char *)0 = 0;
    printf("If we got here, it means that the program continued after the seg fault occurred.\n");
    return 0;
}