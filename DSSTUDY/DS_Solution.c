#include "Dequeue.h"

#include <stdio.h>
#include <malloc.h>

// The definition of the following functions should be in "Dequeue.c"
Dequeue *CreateDequeue(int max_size)
{
	Dequeue * d;
	d->right = 0;
	d->left = max_size - 1;
	d->max_size = max_size;
	d->dequeue = (int*)malloc(sizeof(int)*max_size);

	return d;
}
void DestroyDequeue(Dequeue *d)
{
	free(d->dequeue);
	return;
}

// Dequeue operation
void PushLeft(Dequeue *d, int item)
{
	if (IsFullDequeue(d)) {
		printf("Dequeue is full!\n");
		return;
	}


}
void PushRight(Dequeue *d, int item)
{
	if (IsFullDequeue(d)) {
		printf("Dequeue is full!\n");
		return;
	}


}
int PopLeft(Dequeue *d)
{
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}


}
int PopRight(Dequeue *d)
{
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}


}
int IsFullDequeue(Dequeue *d)		// if d is full, return 1, otherwise, 0
{

}
int IsEmptyDequeue(Dequeue *d)		// if d is empty, return 1, otherwise, 0
{

}
void DisplayDequeue(Dequeue *d)		// display current content of d, provided
{
	int i = 0;

	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}

	printf("(left = %d, right = %d, max_size = %d)\n", d->left, d->right, d->max_size);

	//print column numbers
	for (i = 0; i < d->max_size; i++)
		printf("%3d ", i);
	printf("\n");

	// print contents
	if (d->left <= d->right) {
		for (i = 0; i < d->left; i++)
			printf("   ");
		for (; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
	}
	else {
		for (i = 0; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
		for (; i < d->left; i++)
			printf("   ");
		for (; i < d->max_size; i++)
			printf("%3d ", d->dequeue[i]);
	}

	printf("\n");
}