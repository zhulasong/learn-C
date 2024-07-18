
#include"queue.h"
#include<stdio.h>
#include<stdlib.h>
//队列初始化
void queueInit(Queue* q){
	//初始化空队列
	q->_front = q->_rear = NULL;
	q->_size = 0;
}
//创建节点
QNode* creatNode(QDataType data){
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_next = NULL;
	return node;
}

//入队,从队尾入队
void queuePush(Queue* q, QDataType data){
	QNode* node = creatNode(data);
	//空队列
	if (q->_front == NULL)
		q->_front = q->_rear = node;
	else{
		q->_rear->_next = node;
		q->_rear = node;
	}
	++q->_size;
}
//队头出队 头删
void queuePop(Queue* q){
	if (q->_front){
		QNode* next = q->_front->_next;
			free(q->_front);
			q->_front = next;
			//删除之后是否为空表
			if (q->_front == NULL)
				q->_rear = NULL;
			--q->_size;
	}
}
//获取队头元素
QDataType queueFront(Queue* q){
	return q->_front->_data;
}

//获取队尾元素
QDataType queueBack(Queue* q){
	return q->_rear->_data;
}

int queueSize(Queue* q){
	//int num = 0;
	//QNode* cur = q->_front;
	//while (cur){
	//	++num;
	//	cur = cur->_next;
	//}
	//return num;
	return q->_size;
}
//队列是否为空
int queueEmpty(Queue* q){
	if (q->_front == NULL)
		return 1;
	return 0;
}
//销毁
void queueDestory(Queue* q){
	//从头开始进行释放
	QNode* cur = q->_front;
	while (cur){
		QNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
	q->_size = 0;
	
}

