#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//int main(){
//	for (int n = 1; n < 10; n++){
//		printf("%d *", n);
//		for (int m = 1; m < 10; m++){
//			printf("  %d",m);
//			int c = n * m;
//			printf("     =%d\n", c);
//		}
//	}
//	system("pause");
//	return 0;
//
//}
int main(){
	for (int i = 1; i < 10; i++){
		for (int j = 1; j <= i; j++){
			printf("%d * %d = %2d ",i,j,i * j);
		}
	}
	printf("\n");
	system("pause");
	return 0;
}