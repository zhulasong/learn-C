#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void test(){
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);

	queuePop(&q);
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);

	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);

}
void test2(){
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	queuePush(&q, 4);
	while (queueEmpty(&q) != 1){
		printf("%d ", queueFront(&q));
		queuePop(&q);
	}
	printf("\n");
}

int main(){

	test();
	system("pause");
	return 0;
}