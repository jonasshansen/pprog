#include <stdio.h>
/* Declare functions */
int add(int a, int b);
int disp(int c);

int main()
{
	/* Declare variables */
	int a;
	int b;	

	printf("Enter an integer value:     ");
	scanf("%i", &a);

	printf("Enter yet an integer value: ");
	scanf("%i", &b);
	
	int sum = add(a, b);
	
	printf("The result is:              ");
	disp(sum);
	return 0;
}
