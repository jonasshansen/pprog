#include<stdio.h>
#include<math.h>
double integral1(double,double);
double integral2(double);
double integral2norm(double);

int main(){
	double a = 0, b = 1;	

	printf("Integral of ln(x)/sqrt(x) from 0 to 1:\n%g\n",integral1(a,b));	

	printf("\nVariational method:\nalpha\tE(alpha)\n");
	for(double alpha = 0.1; alpha < 2; alpha += 0.1){
		printf("%g\t%g\n",alpha,integral2(alpha)/integral2norm(alpha));
	}
	return 0;
}
