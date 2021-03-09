/**
 * Test code for Stack 
 *
 * Ying Li
 * 08/01/2016
 */

#include "cstk.h"

int main (int argc, char **argv) {
	Stack *s = stk_create(CSTK_MAX);
	
	int i;
	for(i = 0; i < 10; i++) {
		stk_push(s, i);
	} 
	
	printf("The original list: ");
	stk_display(s, 0);
	
	printf("The reversed list: ");
	stk_display(s, 1);
	
	stk_destroy(s);
	
	return 0;
}