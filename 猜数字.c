#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>


int Menu(){
	printf("===============\n");
	printf("����������ѡ��: \n");
	printf("1.��ʼ��Ϸ \n");
	printf("0.�˳�     \n");
	printf("===============\n");
	int choice = 0;
	scanf("%d",&choice);
	return 1;
}

void Game(){
	int toGuess = rand() % 100 + 1;
	while (2){
		printf("�����������: ");
		int num = 0;
		scanf("%d",&num);
		if (num < toGuess){
			printf("����,�ٸߵ�\n");
		}
		else if (num > toGuess){
			printf("����,���͵�\n");
		}
		else{
			printf("��ϲ�¶���!\n");
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
