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
//	for (int i = 100; i <= 200; i++) // ����100��200֮���ÿ����
//	{
//		int flg = 1;// flg���ڱ���Ƿ�Ϊ��������ʼ����Ϊ����
//		int j = 0;
//		for (j = 2; j < i; j++) // ����2��i-1֮���ÿ����
//		{
//			if (i % j == 0) // ��i�ܱ�j��������i��������
//			{
//				flg = 0;// �޸�flg���Ϊ0����ʾi��������
//				break;    // �˳��ڲ�ѭ������������ж�
//			}
//		}
//
//		if  (flg != 0)// ��flgΪ1����ʾi������
//		{
//			printf("%d ", i); // �������i
//		}
//	}
//	system("pause");
//	return 0;
//}
//
//	