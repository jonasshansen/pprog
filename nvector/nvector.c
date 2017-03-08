#include<stdio.h>
#include<stdlib.h>
#include"nvector.h"
#include<math.h>

nvector* nvector_alloc(int n){
  nvector* v = malloc(sizeof(nvector));
  (*v).size = n;
  (*v).data = malloc(n*sizeof(double));
  if( v==NULL ) fprintf(stderr,"error in nvector_alloc\n");
  return v;
}

void nvector_free(nvector* v){ free(v->data); free(v); v=NULL; }

void nvector_set(nvector* v, int i, double value){ (*v).data[i]=value; }

double nvector_get(nvector* v, int i){return (*v).data[i]; }

double nvector_dot_product(nvector* u, nvector* v){
	double result = 0.0;
	int i;
	for(i=0;i<(*u).size;i++){result += (*u).data[i] * (*v).data[i];}
	return result;
}

void nvector_print(char* s, nvector* v){
	printf("%s\n",s);
	int i;
	for(i=0;i<(*v).size;i++){printf("%g ",(*v).data[i]);}
	printf("\n");
}

void nvector_set_zero(nvector* v){
	int i;
	for(i=0;i<(*v).size;i++){(*v).data[i]=0.0;}
}

int nvector_equal(nvector* a, nvector* b){
	int result = 1;
	int i;
	for(i=0;i<(*a).size;i++){if( (*a).data[i] != (*b).data[i]){result = 0;}}
	return result;
}

void nvector_add(nvector* a, nvector* b){
	int i;
	for(i=0;i<(*a).size;i++){(*a).data[i] = (*a).data[i] + (*b).data[i];}
}

void nvector_sub(nvector* a, nvector* b){
	int i;
	for(i=0;i<(*a).size;i++){(*a).data[i] = (*a).data[i] - (*b).data[i];}
}

void nvector_scale(nvector* a, double x){
	int i;
	for(i=0;i<(*a).size;i++){(*a).data[i] = x*(*a).data[i];}
}
