#include<stdio.h>
#include<stdlib.h>
  
//如果返回 1 认为是素数.如果返回 0 ,认为不是素数.
int Isprise(int num){
	if (num == 0){
		return 0;
	}if (num == 1){
		return 1;
	}
	//找一下num能被哪些数整除.
	//找反例,只要找到一个数字能被 num 整除,说明他不是素数.
	for (int i = 2; i <= num; i++){
		if (num % i == 0){
			return 0;
		}
	}
	return 1;
}

int IsleapYear(int year){
	//世纪闰年和普通闰年
	if (year % 100 == 0){
		if (year % 400 == 0){
			return 0;
		}
		return 1;
	}
	else{
		//普通闰年
		if (year % 4 == 0){
			return 1;
		}
		return 0;
	}
}
//通过这个函数来完成二分查找
//数组是有序的
int binarysearch(int arr[], int size,int toFind){
	int left = 0;
	int right = size - 1;//最后一个元素的下标
		// [left,right] 前闭后闭区间待查找区间
	while (left <= right){
		int mid = (left + right) / 2;
		if (arr[mid] > toFind){
			//左边找
			right = mid - 1;
		}
		else if (arr[mid] < toFind){
			//右边找
			left = mid + 1;
		}
		else{
			//找到了
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