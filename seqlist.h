typedef int SLDataType;

typedef struct seqList{
	SLDataType* _data; //需要动态开辟的数组
	size_t _size; //有效元素的个数
	size_t _capacity; //当前可以存放的最大元素个数
}seqList;

void initSeqList(seqList* sl);

//尾插一个数据
void pushBack(seqList* sl, SLDataType val);

void checkCapacity(seqList* sl);

void printSeList(seqList* sl);

void popBack(seqList* sl);