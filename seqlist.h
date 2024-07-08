typedef int SLDataType;

typedef struct seqList{
	SLDataType* _data; //��Ҫ��̬���ٵ�����
	size_t _size; //��ЧԪ�صĸ���
	size_t _capacity; //��ǰ���Դ�ŵ����Ԫ�ظ���
}seqList;

void initSeqList(seqList* sl);

//β��һ������
void pushBack(seqList* sl, SLDataType val);

void checkCapacity(seqList* sl);

void printSeList(seqList* sl);

void popBack(seqList* sl);