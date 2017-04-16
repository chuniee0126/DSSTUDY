#include "MinHeap.h"

#include <stdio.h>
#include <malloc.h>

MinHeap* CreateMinHeap(int max_size) {
	MinHeap * temp = (MinHeap*)malloc(sizeof(MinHeap));

	temp->array = (int*)malloc(sizeof(int)*(max_size + 1));
	temp->max_size = max_size;
	temp->size = 0;

	return temp;
}

void FreeMinHeap(MinHeap *h) {
	free(h);
}

int IsFullMinHeap(MinHeap *h) {
	if (h->max_size == h->size)
		return 1;
	else
		return 0;
}

int IsEmptyMinHeap(MinHeap *h) {
	if (h->size == 0)
		return 1;
	else
		return 0;
}

void InsertMinHeap(MinHeap *h, int data) {
	int size = (h->size) + 1;

	if (IsFullMinHeap(h)) {
		printf("MinHeap is already Full!\n");
		return;
	}

	while (size > 1) {
		if (data < h->array[size / 2]) {
			h->array[size] = h->array[size / 2];
			size = size / 2;
		}
		/*else if (data == h->array[size / 2]) {
			printf("this data is already in Heap!\n");
			return;
		}*/
		else
			break;
	}

	h->array[size] = data;
	h->size++;

	return;

}

int DeleteMinHeap(MinHeap *h) {

	int root = 1;
	int answer = h->array[root];
	
	while (root <= h->size) {
		if (h->array[root * 2] < h->array[root * 2 + 1]) {
			h->array[root] = h->array[root * 2];
			root = root * 2;
		}
		else {
			h->array[root] = h->array[root * 2 + 1];
			root = root * 2 + 1;
		}
	}

	h->array[root / 2] = h->array[h->size];
	h->size--;

	return answer;

}