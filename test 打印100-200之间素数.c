#include<stdio.h>
#include<stdlib.h>


int main()
{
	for (int i = 100; i < 200; i++){
		int flg = 1;
		for (int n = 2; n < i; n++){
			if (i % n == 0){		
				flg = 0;
				break;
			}	
		}
		if (flg != 0){
			printf(" %d", i);
		}
	}
	system("pause");
	return 0;
}

//int main()
//{
//	int flg = 0;
//	for (int i = 100; i <= 200; i++) // 遍历100到200之间的每个数
//	{
//		int flg = 1;// flg用于标记是否为素数，初始假设为素数
//		int j = 0;
//		for (j = 2; j < i; j++) // 遍历2到i-1之间的每个数
//		{
//			if (i % j == 0) // 若i能被j整除，则i不是素数
//			{
//				flg = 0;// 修改flg标记为0，表示i不是素数
//				break;    // 退出内层循环，无需继续判断
//			}
//		}
//
//		if  (flg != 0)// 若flg为1，表示i是素数
//		{
//			printf("%d ", i); // 输出素数i
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//	