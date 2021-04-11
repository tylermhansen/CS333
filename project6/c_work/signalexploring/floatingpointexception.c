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
  
// Handler for SIGFPE, caused by a floating point exception like dividing by 0.
void handle_sigfpe(int sig){
    printf("\nCaught Floating point signal.\n");
}

int main()
{
    signal(SIGFPE, handle_sigfpe);
    printf("Heading to divide 42 by zero...\n");
    double x = 0.0;
    double illegal = 42 / x;
    printf("%f", illegal);
    printf("If we got here, it means that the program continued after the floating point error occurred.\n");
    return 0;
}