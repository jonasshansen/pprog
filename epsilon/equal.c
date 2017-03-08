int equal(double a, double b, double tau, double epsilon){
	int result=0;
	if(abs(a-b)<tau || abs(a-b)/(abs(a)+abs(b))<epsilon/2){result=1;};
	printf("\n%g\n",abs(a-b));
	printf("\n%g\n",abs(a-b)/(abs(a)+abs(b)));
	printf("\n%g\n",a);
	printf("\n%g\n",b);	
	return result;
}


