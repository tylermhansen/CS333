/**
* Project 1 Memory Access Program: A simple program in which variables are declared and memory accesses in C are explored.
*
* Tyler Hansen
* CS333 Spring 2021
* 02/24/2021 
*/

#include <stdio.h>
#include <stdlib.h>
        
/* Simply declares variables of different types and uses a pointer combined with
C's sizeof() method to explore how many bytes are allocated in memory for each type
and the endian-ness of my machine.
*/ 
int main (int arg, char *argv[]) {
  char var_char = 'c';
  short var_short = 32767;
  int var_int = 0x01234567;
  long var_long = 4242;
  float var_float = 4242.42;
  double var_double = 4242.4242;
  
  int i = 0x01234567;
  unsigned char *ptr;

  ptr = (unsigned char *)&(var_int);
  printf("Integer Loop:\n");
  for(int i=0; i<sizeof(int); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

  ptr = (unsigned char *)&(var_double);
  printf("Double Loop:\n");
  for(int i=0; i<sizeof(double); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

  ptr = (unsigned char *)&(var_short);
  printf("Short Loop:\n");
  for(i=0; i<sizeof(short); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

  ptr = (unsigned char *)&(var_long);
  printf("Long Loop:\n");
  for(i=0; i<sizeof(long); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

  ptr = (unsigned char *)&(var_float);
  printf("Float Loop:\n");
  for(i=0; i<sizeof(float); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}

  ptr = (unsigned char *)&(var_char);
  printf("Character Loop:\n");
  for(i=0; i<sizeof(char); i++) {
	    printf("%d: %02X\n", i, ptr[i]);
	}
				
      return 0;
    }  