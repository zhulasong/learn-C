#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void BubbleSort(int arr[], int size){
	for (int bound = 0; bound < size; bound++){
		for (int ret = size - 1; ret > bound; ret--){
			if (arr[ret] < arr[ret - 1]){
				int tmp = arr[ret];
				arr[ret] = arr[ret - 1];
				arr[ret - 1] = tmp;
			}
		}
	}
}
int main(){
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	printf("ÇëÊäÈë");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	int arr[] = { a, b, c, d };
	BubbleSort(arr, 4);

	for (int i = 0; i < 4; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}