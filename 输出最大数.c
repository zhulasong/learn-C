#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//
int main(){
	int arr[10] = {0};

	for (int n = 1; n < 10; n++){
		scanf(" %d",&arr[n]);
	}
	int max = arr[0];
	for (int n = 1; n < 10; n++){
		if (arr[n] > max){
			max = arr[n];
		}
	}
	printf("最大值为 %d\n",max);
	system("pause");
	return 0;

}