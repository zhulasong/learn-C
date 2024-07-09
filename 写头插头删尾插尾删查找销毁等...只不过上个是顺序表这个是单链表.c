#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int LDataType;
typedef struct listNode{
	LDataType _data;
	struct listNode* _next;
}listNode;

typedef struct list{
	//存放第一个节点的地址
	listNode* _head;
}list;

void listInit(list* lst){
	//初始化为空的链表
	if (lst == NULL)
		return;
	lst->_head = NULL;
}

listNode* creatNode(LDataType val){
	listNode* node = (listNode*)malloc(sizeof(listNode));
	node->_data = val;
	node->_next = NULL;
	return node;
}
//尾插
void listPushBack(list* lst,LDataType val){
	if (lst == NULL)
		return;
	//第一种 空链表插入第一个数据
	if (lst->_head == NULL){
		//创建节点
		lst->_head = creatNode(val);
	}
	else{
		//遍历,找到最后一个节点
		listNode* tail = lst->_head;
		while (tail->_next != NULL){
			tail = tail->_next;
		}
		//插入
		tail->_next = creatNode(val);
	}

}
//尾删
void listPopBack(list* lst){
	
	if (lst == NULL || lst->_head == NULL)
		return;

	struct listNode* tail = lst->_head;
	struct listNode* prev = NULL;
	//遍历 找到最后一个节点
	while (tail->_next != NULL){
		prev = tail;
		tail = tail->_next;
	}
	//删除节点
	free(tail);
	//修改指向
	if (prev = NULL) //删除的是头结点,更新头结点
		lst->_head = NULL;
	else
	prev->_next = NULL;
}

//头插
void listPushFront(list* lst, LDataType val){
	if (lst == NULL)
		return;
	//空的链表,插入第一个数据
	if (lst->_head == NULL)
		lst->_head = creatNode(val);
	else{
		listNode* node = creatNode(val);
		listNode* next = lst->_head;
		//head,node,next
		lst->_head = node;
		node->_next = next;
	}
}

void listPopFront(list* lst){
	if (lst == NULL || lst->_head == NULL)
		return;
	struct listNode* next = lst->_head->_next;
	//释放头结点
	free(lst->_head);
	lst->_head = next;
}

void test(){
	list lst;
	listInit(&lst);
	listPushBack(&lst, 1);
	listPushBack(&lst, 2);
	listPushBack(&lst, 3);
	listPushBack(&lst, 4);
	listPushBack(&lst, 5);

	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);
	listPopBack(&lst);

	listPushFront(&lst, 5);
	listPushFront(&lst, 4);
	listPushFront(&lst, 3);
	listPushFront(&lst, 2);
	listPushFront(&lst, 1);

	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
	listPopFront(&lst);
}

int main(){

	test();
	system("pause");
	return 0;
}