#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>


int Menu(){
	printf("===============\n");
	printf("请输入您的选择: \n");
	printf("1.开始游戏 \n");
	printf("0.退出     \n");
	printf("===============\n");
	int choice = 0;
	scanf("%d",&choice);
	return 1;
}

void Game(){
	int toGuess = rand() % 100 + 1;
	while (2){
		printf("请输入该数字: ");
		int num = 0;
		scanf("%d",&num);
		if (num < toGuess){
			printf("低了,再高点\n");
		}
		else if (num > toGuess){
			printf("高了,往低点\n");
		}
		else{
			printf("恭喜猜对了!\n");
			break;
		}
	}
}

int main(){
	//srand((unsigned int)time (0));
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else {
			printf("Goodbye\n");
			break;
		}
	}
	system("pause");
	return 0;
}
