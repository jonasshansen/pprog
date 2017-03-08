#include<stdio.h>
#include<math.h>
#include<complex.h>

int main()
{
    // double a = tgamma(5);
    printf("Gamma function of 5:\n%g\n",tgamma(5));

    // double b = erf(0.5);
    printf("Bessel function (erf) of 0.5:\n%g\n",erf(0.5));

    complex d1 = csqrt(-2);
    printf("Square root of -2:\n%g + %gi\n",creal(d1),cimag(d1));

    complex d2 = cexp(I);
    printf("exp^i:\n%g + %gi\n",creal(d2),cimag(d2));

    complex d3 = cexp(I * M_PI);
    printf("exp^(i * pi):\n%g + %gi\n",creal(d3),cimag(d3));

    complex d4 = pow(I,M_E);
    printf("i^e:\n%g + %gi\n",creal(d4),cimag(d4));


	float a = 		0.1111111111111111111111111111;
	double b = 		0.1111111111111111111111111111;
	long double c = 0.1111111111111111111111111111;
	
	printf("Significant digits of popular data types illustrated:\n");

	printf("float:      %.25g\n",a);
	printf("double:     %.25lg\n",b);
	printf("long double:%.25Lg\n",c);

	return 0;
}
