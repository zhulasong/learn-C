#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>

void Game(){
	//1.ϵͳ�Զ�����һ������,�����
	int toGuess = rand() % 100 + 1;
	while (1) {
		//2.���û�����һ������
		printf("������һ������(1-100):");
		int num = 0;
		scanf("%d", &num);
		if (num < toGuess){
			printf("����\n");
		}
		else if (num > toGuess){
			printf("����\n");
		}
		else{
			printf("�¶���\n");
			break;
		}
	}
}

int Menu() {
	printf("============\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.�˳���Ϸ\n");
	printf("============\n");
	printf("��������ѡ��:\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

int main(){
	//ʱ��
	//time ���� �õ��������
	//time_t => unsigned long long
	//srand => unsigned int
	srand((unsigned int)time(0));
	//��������Ϸ
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