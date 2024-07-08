#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"seqlist.h"

//typedef struct seqList{
//	SLDataType* _data; //需要动态开辟的数组
//	size_t _size; //有效元素的个数
//	size_t _capacity; //挡枪可以存放的最大元素个数
//}seqList;

void initSeqList(seqList* sl){
	sl->_data = NULL;
	sl->_size = sl->_capacity = 0;
}

//尾插一个数据o(1)
void pushBack(seqList* sl, SLDataType val){
	//检查容量
	checkCapacity(sl);
	sl->_data[sl->_size] = val;
	++sl->_size;
}

void checkCapacity(seqList* sl){
	//如果元素个数和容量相同,说明空间满了,需要扩容空间
	if (sl->_size == sl->_capacity){
		int newCapacity = sl->_capacity == 0 ? 1 : 2 * sl->_capacity;
		//开一个更大的空间,拷贝已有数据,释放原有空间
		SLDataType* tmp = (SLDataType*)malloc(sizeof(SLDataType)* newCapacity);
		memcpy(tmp, sl->_data, sizeof(SLDataType)* sl->_size);
		free(sl->_data);
		//更新
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

//头插 给顺序表的第一个位置插入元素o(n)
//一般不进行头插:效率低
void pushFront(seqList* sl, SLDataType val){
	if (sl == NULL)
		return;
	//0.检查容量
	checkCapacity(sl);
	//1.移动元素:从后向前移动
	int end = sl->_size;
	while (end > 0){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//2.头插
	sl->_data[0] = val;

	sl->_size++;
}
//头删: 移动元素:[1,size)全部向前移动一个位置
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

//插入
void insert(seqList* sl, int pos, SLDataType val){
	//检查容量
	if (sl == NULL)
		return;
	checkCapacity(sl);
	//移动元素
	int end = sl->_size;
	while (end > pos){
		sl->_data[end] = sl->_data[end - 1];
		--end;
	}
	//插入数据
	sl->_data[pos] = val;
	//更新
	sl->_size++;
}

//删除的操作
void erase(seqList* sl, int pos){
	if (sl == NULL || sl->_size == 0)
		return;
	//有效位置:[0,size)
	if (pos >= 0 && pos < sl->_size){
		//1.移动元素:(pos,size),从pos + 1开始,从前往后依次移动
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