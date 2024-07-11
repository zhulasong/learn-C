#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;
//˳���ʵ��һ��ջ
typedef struct stack{
	STDataType* _data;
	int _size;
	int _capacity;
}stack;

void stackInit(stack* st){
	if (st == NULL)
		return;
	st->_data = NULL;
	st->_size = st->_capacity = 0;
}

void checkCapcacity(stack* st){
	if (st->_size == st->_capacity){
		int newCapcacity = st->_capacity == 0 ? 1 : 2 * st->_capacity;
		st->_data = (STDataType*)realloc(st->_data, sizeof(STDataType)* newCapcacity);
		st->_capacity = newCapcacity;
	}

}

//��ջ
void stackPush(stack* st, STDataType val){
	if (st == NULL)
		return;
	checkCapacity(st);
	//β��
	st->_data[st->_size++] = val;

}

//��ջ
void stackPop(stack* st){
	if (st == NULL)
		return;
	if (st->_size > 0)
		st->_size--;
}

STDataType stackTop(stack* st){
	return st->_data[st->_size - 1];
}

void test(){
	stack st;
	stackInit(&st);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	stackPush(&st, 4);
	for (int i = 0; i < 4; ++i){
		printg("%d", stackTop(&st));
		stackPop(&st);
	}
	printf("\n");
}

int main(){
	test();
	system("pause");
	return 0;
}