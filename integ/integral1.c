#include<math.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_errno.h>

double integrand1(double x, void* params){
	return log(x) / sqrt(x);
}

double integral1(double a, double b){
	gsl_function f;
	f.function = integrand1;
	
	int limit = 100;

	double acc = 1e-6, eps = 1e-6, result, err;
	gsl_integration_workspace * workspace = gsl_integration_workspace_alloc(limit);

	int status = gsl_integration_qags(&f, a, b, acc, eps, limit, workspace, &result, &err);
	
	gsl_integration_workspace_free(workspace);

	if(status!=GSL_SUCCESS) return NAN;
	else return result;
}
