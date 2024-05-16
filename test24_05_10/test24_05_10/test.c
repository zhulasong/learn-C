#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

void Game(){
	//1.系统自动生成一个数字,随机数
	int toGuess = rand() % 100 + 1;
	while (1) {
		//2.让用户输入一个整数
		printf("请输入一个整数(1-100):");
		int num = 0;
		scanf("%d", &num);
		if (num < toGuess){
			printf("低了\n");
		}
		else if (num > toGuess){
			printf("高了\n");
		}
		else{
			printf("猜对了\n");
			break;
		}
	}
}

int Menu() {
	printf("============\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("============\n");
	printf("输入您的选择:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main(){
	//时间
	//time 函数 得到随机种子
	//time_t => unsigned long long
	//srand => unsigned int
	srand((unsigned int)time(0));
	//猜数字游戏
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else{
			printf("bye\n");
			break;
		}
	}


	system("pause");
	return 0;

}