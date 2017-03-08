#include<stdio.h>
#include"komplex.h"

void komplex_print (char *s, komplex a) {
	printf ("%s (%g,%g)\n", s, a.re, a.im);
}

komplex komplex_new (double x, double y) {
	komplex z = { x, y };
	return z;
}

void komplex_set (komplex* z, double x, double y) {
	(*z).re = x;
	(*z).im = y;
}

komplex komplex_add (komplex a, komplex b) {
	komplex result = { a.re + b.re , a.im + b.im };
	return result;
}

komplex komplex_sub (komplex a, komplex b) {
	komplex result = { a.re - b.re , a.im - b.im };
	return result;
}
int komplex_equal (komplex a, komplex b) {
	int result;
	if ( a.re == b.re && a.im == b.im ) {
		int result = 1;
	}
	else {
		int result = 0;
	}
	return result;
}
/*

komplex komplex_mul (komplex a, komplex b) {
	komplex result = { a.re*b.re + a.im*b.im , a.re*b.im + a.im*b.re };
	return result;
}

komplex komplex_div (komplex a, komplex b) {
	double den = pow(b.re,2) + pow(b.im,2);
	komplex result = { (a.re*b.re + a.im*b.im) / den , (a.im*b.re - a.re*b.im) / den };
	return result;
}

komplex komplex_conjugate (komplex z) {
	komplex result = { z.re , -z.im };
	return result;
}

komplex komplex_abs (komplex z) {
	komplex result = { pow(z.re,2) + pow(z.im,2) , 0 }; // mangler en kvadratrod
	return result;
}

komplex komplex_exp (komplex z) {
	komplex result = 

komplex komplex_sin (komplex z) {
	komplex result = { sin(z.re)*cosh(z.im) , cos(z.re)*sinh(z.im) };
	return result;
}

komplex komplex_cos (komplex z) {
	komplex result = { cos(z.re)*cosh(z.im) , -sin(z.re)*sinh(z.im) };
	return result;
}

komplex komplex_sqrt (komplex z) {
	komplex result =  
	return result;
}
*/
