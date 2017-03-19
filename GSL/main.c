#include<stdio.h> 
#include<gsl/gsl_linalg.h>
#include<gsl/gsl_cblas.h>
#include<gsl/gsl_eigen.h>
#include<math.h>

const int pi = 3.14159265358979323844;

int main(){
	// Solution of a system of equations
	int nsize = 3;
	gsl_vector *b, *x, *x0;
	gsl_matrix *A, *A0;
	gsl_permutation *p;
	int s;
	
	A = gsl_matrix_calloc(nsize, nsize);
	gsl_matrix_set(A, 0, 0, 6.13); gsl_matrix_set(A, 0, 1, -2.90); gsl_matrix_set(A, 0, 2, 5.86);
	gsl_matrix_set(A, 1, 0, 8.08); gsl_matrix_set(A, 1, 1, -6.31); gsl_matrix_set(A, 1, 2, -3.89);
	gsl_matrix_set(A, 2, 0, -4.36); gsl_matrix_set(A, 2, 1, 1.00); gsl_matrix_set(A, 2, 2, 0.19);

	A0 = gsl_matrix_calloc(nsize, nsize);
	gsl_matrix_memcpy(A0, A);

	b = gsl_vector_calloc(nsize);
	gsl_vector_set(b, 0, 6.23);
	gsl_vector_set(b, 1, 5.37);
	gsl_vector_set(b, 2, 2.29);

	x = gsl_vector_calloc(nsize);
	
	p = gsl_permutation_calloc(nsize);

	gsl_linalg_LU_decomp(A, p, &s);
	gsl_linalg_LU_solve(A, p, b, x);


	printf("x =\n");
	gsl_vector_fprintf(stdout, x, "%g");

	printf("\nA =\n");
	gsl_matrix_fprintf(stdout, A0, "%g");

	printf("\nb =\n");
	gsl_vector_fprintf(stdout, b, "%g");

	printf("\nAx =\n");
	x0 = gsl_vector_calloc(nsize);	
	gsl_blas_dgemv(CblasNoTrans, 1.0, A0, x, 0.0, x0);
	gsl_vector_fprintf(stdout, x0, "%g");

	printf("\nNote that the original A has been changed during the solution and is now:\n");
	gsl_matrix_fprintf(stdout, A, "%g");

	gsl_matrix_free(A);
	gsl_vector_free(b);
	gsl_vector_free(x);
	gsl_permutation_free(p);




	// Quantum particle in a box
	int n = 20;
	double scale = 1.0/(n+1);
	gsl_matrix *H = gsl_matrix_calloc(n,n);
	for(int i = 0; i < n/3; i++){
	  	gsl_matrix_set(H,i,i,-2);
  		gsl_matrix_set(H,i,i+1,1);
  	gsl_matrix_set(H,i+1,i,1);
  	}
	gsl_matrix_set(H,n-1,n-1,-2);
	gsl_matrix_scale(H,-1/scale/scale);

	gsl_eigen_symmv_workspace* w =  gsl_eigen_symmv_alloc (n);
	gsl_vector* eval = gsl_vector_alloc(n);
	gsl_matrix* evec = gsl_matrix_calloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);

	gsl_eigen_symmv_sort(eval,evec,GSL_EIGEN_SORT_VAL_ASC);

	
	fprintf (stdout, "\ni   exact   calculated\n");
	for (int k=0; k < n/3; k++){
   		double exact = pi*pi*(k+1)*(k+1);
    	double calculated = gsl_vector_get(eval,k);
    	fprintf (stdout, "%i   %g   %g\n", k, exact, calculated);
	}
	
	for(int k=0;k<3;k++){
  		printf("%g %g\n",0.0,0.0);
  		for(int i=0;i<n;i++) printf("%g %g\n",(i+1.0)/(n+1),gsl_matrix_get(evec,i,k));
  		printf("%g %g\n",1.0,0.0);
  		printf("\n\n");
  	}

	return 0;
}
