#include<stdio.h>
#include<stdlib.h>

int main(){
	//����Ϊ 3 ��һ������,ÿ��Ԫ�س���Ϊ 4.
	int arr[3][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
	};

	for (int i = 0; i < 3; i++){
		//arr[i] �͵õ���һ������Ϊ 4 ��һά����
		for (int j = 0; j < 4; j++){
			printf("\n", arr[i][j]);
		}
		printf(" \n");
	}

	system("pause");
	return 0;
}