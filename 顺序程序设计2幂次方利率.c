#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int p = 1000;
	double a = 0.03;
	double ret1 = p * (1 + a * 5);
	printf("一次存五年 %lf\n",ret1);
	double b = 0.021;
	double c = 0.0275;
	double ret2 = (p * (1 + 2 * b)) * (1 + 3 * c);
	printf("一次存两年再存三年 %lf\n", ret2);
	double ret3 = (p * (1 + 3 * c)) * (1 + 2 * b);
	printf("一次存三年再存两年 %lf\n", ret3);
	double d = 0.015;
	double ret4 = p * pow((1 + d), 5);
	printf("五年存取五次 %lf\n", ret1);
	double e = 0.0035;
	double ret5 = p * pow((1 + e / 4),4 * 5);
	printf("活期存五年 %lf\n", ret5);
	system("pause");
	return 0;
}