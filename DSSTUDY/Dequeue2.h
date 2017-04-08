#ifndef __DEQUEUE2__
#define __DEQUEUE2__

typedef struct tNode
{
	int data;
	struct tNode *llink, *rlink;
} Node;

typedef struct 
{
	Node *left, *right;
} Dequeue;

// the definition of the following functions should be in "Dequeue2.c"
Dequeue *CreateDequeue(int max_size);	// Creates a dequeue, ignore max_size
void DestroyDequeue(Dequeue *d);		// Destroy a dequeue

// Dequeue operations
void PushLeft(Dequeue *d, int item);
void PushRight(Dequeue *d, int item);
int PopLeft(Dequeue *d);
int PopRight(Dequeue *d);
int IsFullDequeue(Dequeue *d);
int IsEmptyDequeue(Dequeue *d);

void DisplayDequeue(Dequeue *d);
void DisplayDequeueReverse(Dequeue *d);

#endif // !__DEQUEUE2__
