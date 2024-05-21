#include<stdio.h>
#include<stdlib.h>

int main(){
	//长度为 3 的一堆数组,每个元素长度为 4.
	int arr[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};

	for (int i = 0; i < 3; i++){
		//arr[i] 就得到了一个长度为 4 的一维数组
		for (int j = 0; j < 4; j++){
			printf("\n", arr[i][j]);
		}
		printf(" \n");
	}

	system("pause");
	return 0;
}