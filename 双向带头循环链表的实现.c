#include<stdio.h>
#include<stdlib.h>

typedef int LDataType;

//˫���ͷѭ������Ľڵ�
typedef struct ListNode{
	LDataType _data;
	//ָ����һ���ڵ����ʼλ��
	struct ListNode* _next;
	//ָ����һ���ڵ����ʼλ��
	struct LIst* _prev;
}ListNode;

//˫���ͷѭ������
typedef struct List{
	struct ListNode* _head;
}List;

struct ListNode* createListNode(LDataType val){
	struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
	node->_data = val;
	node->_next = NULL;
	node->_prev = NULL;
}

void ListInit(List* lst){
	//������
	lst->_head = createListNode(0);
	lst->_head->_next = lst->_head->_prev = lst->_head;

}
//β�� O(1) //��ͷ��ǰ���һ������ListInsert(lst, lst->_head, val);
void ListpushBack(List* lst, LDataType val){
	if (lst == NULL){
		return;
		struct ListNode* last = lst->_head->_prev;
		struct ListNode* newNode = createListNode(val);
		//_head ... last newNode
		last->_next = newNode;
		newNode->_prev = last;

		newNode->_next = lst->_head;
		lst->_head->_prev = newNode;
	}
}

//βɾ://ɾ��ͷ��ǰһ���ڵ� ListErase(lst, lst->_head->_prev);
void ListPopBack(List* lst){
	if (lst == NULL)
		return;
	//�ж��Ƿ������
	if (lst->_head->_next == lst->_head)
		return;
	struct ListNode* last = lst->_head->_prev;
	struct ListNode* prev = last->_prev;

	free(last);

	lst->_head->_prev = prev;
	prev->_next = lst->_head;
}

void printList(List* lst){
	struct ListNode* cur = lst->_head->_next;
	while (cur != lst->_head){
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

//ͷ��//ListInsert(lst,lst->_head->_next,val);
void ListPushFront(List* lst, LDataType val){
	if (lst == NULL)
		return;
	struct ListNode* next = lst->_head->_next;
	struct ListNode* newNode = createListNode(val);

	//_head, newNode, next
	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;

	newNode->_next = next;
	next->_prev = newNode;
}

//ͷɾ//ListErase(lst,lst->_head->_next);
void ListPopFront(List* lst){
	if (lst == NULL || lst->_head  == lst->_head)
		return;
	struct ListNode* next = lst->_head->_next;
	struct ListNode* nextnext = next->_next;
	
	nextnext->_prev = next->_next;
	lst->_head->_next = nextnext;

	free(next);
	
}

void ListErase(List* lst, struct ListNode* node){
	//����ɾ��head�ڵ�
	if (lst == NULL || lst->_head == node)
		return;
	//prev, node, next
	struct ListNode* prev = node->_prev;
	struct ListNode* next = node->_next;

	prev->_next = next;
	next->_prev = prev;

	free(node);

}

void ListInsert(List* lst, struct ListNode* node, LDataType val){
	if (lst == NULL)
		return;
	struct ListNode* prev = node->_prev;
	struct ListNode* newNode = createListNode(val);

	//prev newNode node
	prev->_next = newNode;
	newNode->_prev = prev;

	newNode->_next = node;
	node->_prev = newNode;
}

//����
ListDestoty(List* lst){
	if (lst){
		if (lst->_head){
			struct ListNode* cur = lst->_head->_next;
			while (cur != lst->_head){
				struct ListNode* next = cur->_next;
				free(cur);
				cur = next;
			}

			free(lst->_head);
		}
	}
}

/*void test(){
	*///List lst;
	//ListInit(&lst);
	//ListPushFront(&lst, 5);
	//printList(&lst);
	//ListPushFront(&lst, 1);
	//printList(&lst);
	//ListPushFront(&lst, 2);
	//printList(&lst);
	//ListPushFront(&lst, 3);
	//printList(&lst);
	//ListPushFront(&lst, 4);
	//printList(&lst);
	//ListPopFront(&lst);
	//printList(&lst);
	//ListPopFront(&lst);
	//printList(&lst);
	//ListPopFront(&lst);
	//printList(&lst);



	/*ListPopBack(&lst);
	printList(&lst);
	ListPopBack(&lst);
	printList(&lst);
	ListPopBack(&lst);
	printList(&lst);
	ListPopBack(&lst);
	printList(&lst);*/
//}

int main(){

	test();
	system("pause");
	return 0;
}