#ifndef __MIN_HEAP__
#define __MIN_HEAP__

typedef struct tMinHeap {
	int *array;
	int size;
	int max_size;
} MinHeap;

MinHeap* CreateMinHeap(int max_size);
void FreeMinHeap(MinHeap *h);
int IsFullMinHeap(MinHeap *h);
int IsEmptyMinHeap(MinHeap *h);

void InsertMinHeap(MinHeap *h, int data);
int DeleteMinHeap(MinHeap *h);

#endif // !__MIN_HEAP__
