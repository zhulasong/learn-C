#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int toFind = 3;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left < right){
		int mid = (left + right) / 2;
		if (arr[mid] < toFind){
			left = mid + 1;
		}
		else if (arr[mid] > toFind){
			right = mid - 1;
		}
		else { printf("%d\n", mid);
		break;
		}
	}
	if (left > right){
		printf("找不到该元素\n");
	}

	system("pause");
	return 0;
}