#include<stdio.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<math.h>

int orbital_equation(double phi, double y[], double dydt[], void *params){
	double epsilon = *(double *) params;
	dydt[0] = y[1];
	dydt[1] = 1 - y[0] + epsilon * y[0] * y[0];
	return GSL_SUCCESS;
}


int main(){
double epsilon = 0.02, dydt = -0.8;

gsl_odeiv2_system orbit;
orbit.function = orbital_equation;
orbit.jacobian = NULL;
orbit.dimension = 2;
orbit.params = (void *) &epsilon;

double hstart = 1e-3;
double epsabs = 1e-6, epsrel = 1e-6;
double phi_max = 39.5 * M_PI, delta_phi = 0.05;

gsl_odeiv2_driver *driver = gsl_odeiv2_driver_alloc_y_new(&orbit, gsl_odeiv2_step_rkf45, hstart,
	epsabs, epsrel);

double t = 0, y[2] = {1,dydt};

for(double phi = 0; phi < phi_max; phi += delta_phi){
	gsl_odeiv2_driver_apply(driver, &t, phi, y);
	printf("%g %g\n", phi, y[0]);
}

gsl_odeiv2_driver_free(driver);

return 0;
}
