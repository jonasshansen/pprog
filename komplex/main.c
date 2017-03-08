#include"komplex.h"
#include<stdio.h>
#define TINY 1e-6

int main(){
	komplex a = {1,2}, b = {3,4};

	printf("testing komplex_add...\n");
	komplex r1 = komplex_add(a,b);
	komplex R1 = {4,6};
	komplex_print("a=",a);
	komplex_print("b=",b);
	komplex_print("a+b should   = ", R1);
	komplex_print("a+b actually = ", r1);

	printf("testing komplex_sub...\n");
	komplex r2 = komplex_sub(a,b);
	komplex	R2 = {-2,-2};
	komplex_print("a=",a);
	komplex_print("b=",b);
	komplex_print("a-b should   = ", R2);
	komplex_print("a-b actually = ", r2);


	printf("testing komplex_equal...\n");
	int r3a = komplex_equal(a,b);
	int r3b = komplex_equal(a,a);
	int R3a = 0;
	int R3b = 1;
	komplex_print("a=",a);
	komplex_print("b=",b);
	printf("a==b should   = %i\n", R3a);
	printf("a==b actually = %i\n", r3a);
	printf("a==a should   = %i\n", R3b);
	printf("a==a actually = %i\n", r3b);
	



/*
	if( komplex_equal(R,r,TINY,TINY) )
		printf("test 'add' passed :) \n");
	else
		printf("test 'add' failed: debug me, please... \n");
*/

	return 0;
}
