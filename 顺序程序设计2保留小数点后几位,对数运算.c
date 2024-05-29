#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int d = 300000;
	int p = 6000;
	double r = 0.01;
	double m = log(p / (p - d * r)) / log(1 + r) + 0.05;
	printf("%.1lf",m);
	system("pause");
	return 0;
}