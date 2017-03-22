#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_multimin.h>
#include<math.h>

double rosenbrock(const gsl_vector *v, void *params){
	double x = gsl_vector_get(v,0);
	double y = gsl_vector_get(v,1);
	return pow((1-x),2) + 100*pow(y-x*x,2);
}

int minimize_rosenbrock(){
	int iter = 0, status;
	double acc = 1e-3;
	
	gsl_multimin_function fun;
	fun.f = rosenbrock;
	fun.n = 2;
	
	gsl_vector *v = gsl_vector_alloc(fun.n);
	gsl_vector_set(v,0,2);
	gsl_vector_set(v,1,2);

	gsl_vector *vstep = gsl_vector_alloc(fun.n);
	gsl_vector_set(vstep,0,0.1);
	gsl_vector_set(vstep,1,0.1);

	gsl_multimin_fminimizer *state = gsl_multimin_fminimizer_alloc(gsl_multimin_fminimizer_nmsimplex2,
		fun.n);

	gsl_multimin_fminimizer_set(state, &fun, v, vstep);

	do{
		iter++;
		int status = gsl_multimin_fminimizer_iterate(state);

		if(status != 0){
			fprintf(stderr,"Unable to improve\n");
			break;
		}

		status = gsl_multimin_test_size(state->size, acc);

		if(status == GSL_SUCCESS){
			fprintf(stderr,"Converged\n");
		}
		
		printf("%d\t%f\t%f\t%g\t%g\n", iter, gsl_vector_get(state->v,0), gsl_vector_get(state->v,1),
			state->fval, state->size);
	}
	while( status == GSL_CONTINUE && iter < 100 );

	gsl_vector_free(v);
	gsl_vector_free(vstep);
	gsl_multimin_fminimizer_free(state);
	
	return status;
}
