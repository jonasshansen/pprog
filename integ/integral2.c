#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_errno.h>

double integrand2(double x, void* params){
	double a = *(double*)params;
	return (-a*a*x*x/2 + a/2 + x*x/2)*exp(-a*x*x);
}

double integral2(double a){
	gsl_function f;
	f.function = integrand2;
	f.params = (void*)&a;
	
	int limit = 100;

	double acc = 1e-6, eps = 1e-6, result, err;
	gsl_integration_workspace * workspace = gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qagi(&f, acc, eps, limit, workspace, &result, &err);
	
	gsl_integration_workspace_free(workspace);

	if(status!=GSL_SUCCESS) return NAN;
	else return result;
}
