#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int LDataType;
typedef struct listNode{
	LDataType _data;
	struct listNode* _next;
}listNode;

typedef struct list{
	//��ŵ�һ���ڵ�ĵ�ַ
	listNode* _head;
}list;

void listInit(list* lst){
	//��ʼ��Ϊ�յ�����
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
//β��
void listPushBack(list* lst,LDataType val){
	if (lst == NULL)
		return;
	//��һ�� ����������һ������
	if (lst->_head == NULL){
		//�����ڵ�
		lst->_head = creatNode(val);
	}
	else{
		//����,�ҵ����һ���ڵ�
		listNode* tail = lst->_head;
		while (tail->_next != NULL){
			tail = tail->_next;
		}
		//����
		tail->_next = creatNode(val);
	}

}
//βɾ
void listPopBack(list* lst){
	
	if (lst == NULL || lst->_head == NULL)
		return;

	struct listNode* tail = lst->_head;
	struct listNode* prev = NULL;
	//���� �ҵ����һ���ڵ�
	while (tail->_next != NULL){
		prev = tail;
		tail = tail->_next;
	}
	//ɾ���ڵ�
	free(tail);
	//�޸�ָ��
	if (prev = NULL) //ɾ������ͷ���,����ͷ���
		lst->_head = NULL;
	else
	prev->_next = NULL;
}

//ͷ��
void listPushFront(list* lst, LDataType val){
	if (lst == NULL)
		return;
	//�յ�����,�����һ������
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
	//�ͷ�ͷ���
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