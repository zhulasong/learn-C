#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double r = 1.5;
	double h = 3;
	double pi = acos(-1.0);
	printf("Բ�ܳ�Ϊ %.2lf\n",pi * 2 * r);
	double b = pow(r, 2);
	printf("Բ���Ϊ %.2lf\n",pi * b);
	printf("������Ϊ %.2lf\n",4 * pi * b);
	double c = pow(r,3);
	printf("�����Ϊ %.2lf\n",(4 / 3) * pi * c);
	printf("Բ�����Ϊ %.2lf\n",pi * b * h);
	system("pause");
	return 0;
}