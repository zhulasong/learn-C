#include <stdio.h>
#include <stdlib.h>

void printNum(unsigned int num){
	if (num > 9){
		printNum(num / 10);
	}
	printf("%d ", num % 10);
	return 0;
}

int main(){
	printNum(1234);
	system("pause");
	return 0;
}
