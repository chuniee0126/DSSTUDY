#ifndef __DEQUEUE__
#define __DEQUEUE__

typedef struct {
	int *dequeue;
	int max_size;
	int left;
	int right;
} Dequeue;

// The definition of the following functions should be in "Dequeue.c"
Dequeue *CreateDequeue(int max_size);
void DestroyDequeue(Dequeue *d);

// Dequeue operation
void PushLeft(Dequeue *d, int item);
void PushRight(Dequeue *d, int item);
int PopLeft(Dequeue *d);
int PopRight(Dequeue *d);
int IsFullDequeue(Dequeue *d);		// if d is full, return 1, otherwise, 0
int IsEmptyDequeue(Dequeue *d);		// if d is empty, return 1, otherwise, 0

void DisplayDequeue(Dequeue *d);	// display current content of d, provided

#endif // !__DEQUEUE__
