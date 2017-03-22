#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_errno.h>

double integrand2norm(double x, void* params){
	double a = *(double*)params;
	return exp(-a*x*x);
}

double integral2norm(double a){
	gsl_function f;
	f.function = integrand2norm;
	f.params = (void*)&a;
	
	int limit = 100;

	double acc = 1e-6, eps = 1e-6, result, err;
	gsl_integration_workspace * workspace = gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qagi(&f, acc, eps, limit, workspace, &result, &err);
	
	gsl_integration_workspace_free(workspace);

	if(status!=GSL_SUCCESS) return NAN;
	else return result;
}
