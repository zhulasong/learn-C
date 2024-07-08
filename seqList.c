#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//typedef struct seqList{
//	SLDataType* _data; //��Ҫ��̬���ٵ�����
//	size_t _size; //��ЧԪ�صĸ���
//	size_t _capacity; //��ǹ���Դ�ŵ����Ԫ�ظ���
//}seqList;

void initSeqList(seqList* sl){
	sl->_data = NULL;
	sl->_size = sl->_capacity = 0;
}

//β��һ������o(1)
void pushBack(seqList* sl, SLDataType val){
	//�������
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

void checkCapacity(seqList* sl){
	//���Ԫ�ظ�����������ͬ,˵���ռ�����,��Ҫ���ݿռ�
	if (sl->_size == sl->_capacity){
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//��һ������Ŀռ�,������������,�ͷ�ԭ�пռ�
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)* newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)* sl->_size);
		free(sl->_data);
		//����
		sl->_data = tmp;
		sl->_capacity = newCapacity;
	}
}

void printSeList(seqList* sl){
	for (int i = 0; i < sl->_size; ++i){
		printf("%d", sl->_data[i]);
	}
	printf("\n");
}

void popBack(seqList* sl){
	if (sl == NULL)
		return;
	if (sl->_size>0)
		sl->_size--;
}

//ͷ�� ��˳���ĵ�һ��λ�ò���Ԫ��o(n)
//һ�㲻����ͷ��:Ч�ʵ�
void pushFront(seqList* sl, SLDataType val){
	if (sl == NULL)
		return;
	//0.�������
	checkCapacity(sl);
	//1.�ƶ�Ԫ��:�Ӻ���ǰ�ƶ�
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//2.ͷ��
	sl->_data[0] = val;

	sl->_size++;
}
//ͷɾ: �ƶ�Ԫ��:[1,size)ȫ����ǰ�ƶ�һ��λ��
void popFront(seqList* sl){
	if (sl == NULL || sl->_size == 0)
		return;
	int start = 1;
	while (start < sl->_size){
		sl->_data[start - 1] = sl->_data[start];
		++start;
	}

	--sl->_size;
}

//����
void insert(seqList* sl, int pos, SLDataType val){
	//�������
	if (sl == NULL)
		return;
	checkCapacity(sl);
	//�ƶ�Ԫ��
	int end = sl->_size;
	while (end > pos){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//��������
	sl->_data[pos] = val;
	//����
	sl->_size++;
}

//ɾ���Ĳ���
void erase(seqList* sl, int pos){
	if (sl == NULL || sl->_size == 0)
		return;
	//��Чλ��:[0,size)
	if (pos >= 0 && pos < sl->_size){
		//1.�ƶ�Ԫ��:(pos,size),��pos + 1��ʼ,��ǰ���������ƶ�
		int start = pos + 1;
		while (start < sl-> _size){
			sl->_data[start - 1] = sl->_data[start];
			++start;
		}
		--sl->_size;
	}
}

void test(){
	seqList sl;
	initSeqList(&sl);
	pushBack(&sl, 1 );
	pushBack(&sl, 2 );
	pushBack(&sl, 3 );
	pushBack(&sl, 4 );
	pushBack(&sl, 5 );
	erase(&sl, 3);
	erase(&sl, 2);
	erase(&sl, 0);
	printSeList(&sl);
}

//void test(){
//	seqList sl;
//	initSeqList(&sl);
//	pushBack(&sl, 1);
//	pushBack(&sl, 2);
//	pushBack(&sl, 3);
//	pushBack(&sl, 4);
//	pushBack(&sl, 5);
//	insert(&sl, 1, 10); 
//	insert(&sl, 2, 20);
//	printSeList(&sl);
//	insert(&sl, 0, -1);
//	printSeList(&sl);
//	insert(&sl, sl._size, 3);
//	printSeList(&sl);
//	
//
//}
int main(){
	
	test();
	system("pause");
	return 0;
}