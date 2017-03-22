#include<stdio.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<math.h>

int diff_equation(double x, double y[], double dydx[]){
	dydx[0] = 1 + pow(y[0],2);
	return GSL_SUCCESS;
}

double my_tan(double x){
	if(x<0){return -my_tan(-x);} // tan(x) = -tan(-x)
	double x_r = fmod(x,M_PI); // periodicity (take the modulus pi)
	if(x_r == M_PI/2){return NAN;} // asymptote
	else if(x_r > M_PI/2){return my_tan(x_r-M_PI);} // symmetry
	else{
		gsl_odeiv2_system tangent;
		tangent.function = diff_equation;
		tangent.jacobian = NULL;
		tangent.dimension = 1;
		tangent.params = NULL;
		
		double acc = 1e-6, eps = 1e-6, hstart = 0.1;
		gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new(&tangent, gsl_odeiv2_step_rkf45,
			hstart, acc, eps);

		double t = 0, y[1] = {0.0};
		gsl_odeiv2_driver_apply(driver, &t, x_r, y);

		gsl_odeiv2_driver_free(driver);
		return y[0];
	}
}

int main(int argc, char **argv){
	double x0 = strtod(argv[1], NULL);
	double x1 = strtod(argv[2], NULL);
	double dx = strtod(argv[3], NULL);
	
	for(double x=x0; x <= x1; x+=dx){
		printf("%g\t%g\t%g\n",x,tan(x),my_tan(x));
	}

	return 0;
}
