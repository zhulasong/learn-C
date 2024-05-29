#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double p = 0;
	double a = 0.07;
	double b = 10;
	
	p = pow((1 + a), b);
	printf("%lf",p);
	system("pause");
	return 0;
}