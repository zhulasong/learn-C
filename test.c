#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	
	int i = 0;
	int sum = 0;//保存最终结果
	int n = 0;
	int ret = 1;//保存n的阶乘
	scanf("%d",&n);
	for (i = 1; i <= n; i++){
		ret = 1;
		int j = 0;
		for (j = 1; j <= i; j++){
			ret *= j;
		}
		sum += ret;
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}