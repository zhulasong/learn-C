#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int x = 0;
	int y = 0;
	scanf("%d", &x);
	if (1 <= x < 10){
		y = 2 * x - 1;
	}
	else if (x < 1){
		y = x;
	}
	else y = 3 * x - 11;
	printf("y = %d\n",y);

	system("pause");
	return 0;
}