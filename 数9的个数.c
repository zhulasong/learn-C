#include<stdio.h>
#include<stdlib.h>

int main(){
	int num = 0;
	for (int n = 0; n < 101; n++){
		if ((n - 9) % 10 == 0){
			printf(" %d", n);
			num++;
		}
	}
	printf("\n%d", num);
	system("pause");
	return 0;
}