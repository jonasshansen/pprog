#include <stdio.h>
#include <limits.h>
#include <float.h>

int equal(double, double, double, double);

int main()
{
	// INT_MAX 
	printf("Maximum number INT_MAX:\n");	
	printf("%i\n",INT_MAX);

	printf("Maximum number found with while loop:\n");	
	int i=1;while(i+1>i){i++;};printf("%i\n",i);

	printf("Maximum number found with for loop:\n");
	for(i=1;i+1>i;i++){};printf("%i\n",i);
	
	printf("Maximum number found with do while loop:\n");
	i=1;do{i++;}while(i+1>i);printf("%i\n",i);

	printf("\n");


	// INT_MIN
	printf("Minimum number INT_MIN:\n");	
	printf("%i\n",INT_MIN);

	printf("Minimum number found with while loop:\n");	
	i=1;while(i-1<i){i--;};printf("%i\n",i);

	printf("Minimum number found with for loop:\n");
	for(i=1;i-1<i;i--){};printf("%i\n",i);
	
	printf("Minimum number found with do while loop:\n");
	i=1;do{i--;}while(i-1<i);printf("%i\n",i);

	printf("\n");


	// Machine epsilon
	printf("Machine epsilon for float FLT_EPSILON:\n");
	printf("%g\n",FLT_EPSILON);

	printf("Machine epsilon for float found with while loop:\n");
	float x1=1;while(1+x1!=1){x1/=2;}x1*=2;printf("%g\n",x1);

	printf("Machine epsilon for float found with for loop:\n");
	for(x1=1;1+x1!=1;x1/=2){}x1*=2;printf("%g\n",x1);
	
	printf("Machine epsilon for float found with do while loop:\n");	
	x1=1;do{x1/=2;}while(1+x1/2!=1);printf("%g\n",x1);


	printf("Machine epsilon for double DBL_EPSILON:\n");
	printf("%g\n",DBL_EPSILON);

	printf("Machine epsilon for double found with while loop:\n");
	double x2=1;while(1+x2!=1){x2/=2;}x2*=2;printf("%g\n",x2);

	printf("Machine epsilon for double found with for loop:\n");
	for(x2=1;1+x2!=1;x2/=2){}x2*=2;printf("%g\n",x2);
	
	printf("Machine epsilon for double found with do while loop:\n");	
	x2=1;do{x2/=2;}while(1+x2/2!=1);printf("%g\n",x2);

	
	printf("Machine epsilon for long double LDBL_EPSILON:\n");
	printf("%Lg\n",LDBL_EPSILON);

	printf("Machine epsilon for long double found with while loop:\n");
	long double x3=1;while(1+x3!=1){x3/=2;}x3*=2;printf("%Lg\n",x3);

	printf("Machine epsilon for long double found with for loop:\n");
	for(x3=1;1+x3!=1;x3/=2){}x3*=2;printf("%Lg\n",x3);
	
	printf("Machine epsilon for long double found with do while loop:\n");	
	x3=1;do{x3/=2;}while(1+x3/2!=1);printf("%Lg\n",x3);

	printf("\n");
	

	// Pseudo-infinite sums
	int max=INT_MAX/2;
	float sum_up_float = 0;
	for(i=1;i<=max;i++){sum_up_float+=1.0f/i;} // 1.0f is float, 1.0 is double
	printf("The sum of 1.0f + 1.0f/2 + 1.0f/3 + ... + 1.0f/max for max=INT_MAX/2:\n%g\n",sum_up_float);
	
	float sum_down_float = 0;
	for(i=max;i>0;i--){sum_down_float+=1.0f/i;}
	printf("The sum of 1.0f/max + 1.0f/(max-1) + 1.0f/(max-2) + ... +1.0f:\n%g\n",sum_down_float);

	double sum_up_double = 0;
	for(i=1;i<=max;i++){sum_up_double+=1.0/i;} 
	printf("The sum of 1.0 + 1.0/2 + 1.0/3 + ... + 1.0/max for max=INT_MAX/2:\n%g\n",sum_up_float);
	
	double sum_down_double = 0;
	for(i=max;i>0;i--){sum_down_double+=1.0/i;}
	printf("The sum of 1.0/max + 1.0/(max-1) + 1.0/(max-2) + ... +1.0:\n%g\n",sum_down_float);

	printf("\n");

	
	// Call of equal function
	double a = 1.0;
	double b = 2.0;
	double c = 2.0+DBL_EPSILON;
	double tau = 0.1; 
	double epsilon = DBL_EPSILON;

	printf("tau=%g, epsilon=%g\n\n",tau,epsilon);

	int result = equal(a,b,tau,epsilon);
	printf("%g=%g?\n%i\n\n",a,a,result);
	result = equal(a,c,tau,epsilon);
	printf("%g=%g?\n%i\n\n",a,b,result);
	result = equal(a,a,tau,epsilon);
	printf("%g=%g?\n%i\n\n",a,c,result);
	result = equal(b,c,tau,epsilon);
	printf("%g=%g?\n%i\n\n",a,a,result);


	return 0;
}

