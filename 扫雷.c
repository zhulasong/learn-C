#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINR_COUNT 10

int Menu(){
	printf("==============\n");
	printf("欢迎来到扫雷\n");
	printf("1.开始游戏\n");
	printf("0.退出游戏\n");
	printf("==============\n");
	printf("输入选择 ");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}

void Init(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL]){
	memset(showMap, '*', MAX_ROW * MAX_COL);
	srand((unsigned int)time(0));
	memset(mineMap, "0", MAX_ROW * MAX_COL);
	int count = MINR_COUNT;
	while (count > 0){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1'){
			continue;
		}
		mineMap[row][col] = '1';
		count--;
	}
}

void Print(char showMap[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			printf("%c ",showMap[row][col]);
		}
		printf("\n");
	}
}

void Input(char showMap[MAX_ROW][MAX_COL], int* row, int* col){
	while (1){
		printf("请输入要翻开位置的坐标(row, col):");
		scanf("%d %d",row, col);
		if (*row < 0 || *row >= MAX_ROW || *col < 0 || *col >= MAX_COL){
			printf("您的输入有误\n");
			continue;
		}
		if (showMap[*row][*col] != '*'){
			printf("当前位置已经被翻开\n");
			continue;
		}
		break;
	}
}

int CheckMine(char mineMap[MAX_ROW][MAX_COL],
	int row, int col){
	if (mineMap[row][col] == '1'){
		return 1;
	}
	return 0;
}

int CheceLastBlank(int* count){
	*count += 1;
	if (*count == 71){
		return 1;
	}
	return 0;
}

void Update(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL], int row, int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c < col + 1; c++){
			if (r < 0 || r >= MAX_ROW
				|| c < 0 || c >= MAX_COL){
				continue;
			}
			if (mineMap[r][c] == '1'){
				count++;
			}
		}
	}
	showMap[row][col] = count + '0';
}

void Game(){
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	int count = 0;
	Init(showMap, mineMap);
	while (1){
		Print(showMap);
		int row = 0;
		int col = 0;
		Input(showMap, &row, &col);
		if (CheckMine(mineMap, row, col)){
			printf("踩雷\n");
			break;
		}
		if (CheceLastBlank(&count)){
			printf("成功扫雷\n");
		}
		Update(showMap,mineMap,row,col);
	}
}

int main(){
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("GoodBye!\n");
		}
		else{
			printf("输入有误\n");
		}
	}
	system("pause");
	return 0;
}