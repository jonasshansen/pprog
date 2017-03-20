#include<stdio.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<math.h>

int error_function(double t, double y[], double dydt[], void *params){
	dydt[0] = 2/sqrt(M_PI) * exp( -t * t);
	return GSL_SUCCESS;
}

double ode_solver(double x){
	gsl_odeiv2_system sys;
	sys.function = error_function;
	sys.jacobian = NULL;
	sys.dimension = 1;
	sys.params = NULL;

	double acc = 1e-6, eps = 1e-6, hstart = copysign(0.1,x);
	gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rkf45,
		hstart, acc, eps);

	double t = 0, y[1] = {0.0};
	gsl_odeiv2_driver_apply(driver, &t, x, y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}


int main(int argc, char **argv){
	double a = strtod(argv[1], NULL), b = strtod(argv[2], NULL), dt = strtod(argv[3], NULL);
	
	for(double t = a; t < b; t += dt){	
		printf("%g\t %g\n", t, ode_solver(t));
	}
	
	return 0;
}
