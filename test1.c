#include<stdio.h>
#include<stdlib.h>
  
//������� 1 ��Ϊ������.������� 0 ,��Ϊ��������.
int Isprise(int num){
	if (num == 0){
		return 0;
	}if (num == 1){
		return 1;
	}
	//��һ��num�ܱ���Щ������.
	//�ҷ���,ֻҪ�ҵ�һ�������ܱ� num ����,˵������������.
	for (int i = 2; i <= num; i++){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}

int IsleapYear(int year){
	//�����������ͨ����
	if (year % 100 == 0){
		if (year % 400 == 0){
			return 0;
		}
		return 1;
	}
	else{
		//��ͨ����
		if (year % 4 == 0){
			return 1;
		}
		return 0;
	}
}
//ͨ�������������ɶ��ֲ���
//�����������
int binarysearch(int arr[], int size,int toFind){
	int left = 0;
	int right = size - 1;//���һ��Ԫ�ص��±�
		// [left,right] ǰ�պ���������������
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] > toFind){
			//�����
			right = mid - 1;
		}
		else if (arr[mid] < toFind){
			//�ұ���
			left = mid + 1;
		}
		else{
			//�ҵ���
			return mid;
		}
	}
	return -1;
}

void func(int* x){
	*x += 1;
}

int main(){
	int num = 0;
	func(&num);
	printf("num = %d\n", num);
	system("pause");
	return 0;
}