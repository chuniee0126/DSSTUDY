#include "Dequeue.h"

#include <stdio.h>
#include <malloc.h>

// The definition of the following functions should be in "Dequeue.c"
Dequeue *CreateDequeue(int max_size)
{
	Dequeue * temp = (Dequeue*)malloc(sizeof(Dequeue));
	temp->right = 0;
	temp->left = 0;
	temp->max_size = max_size;
	temp->dequeue = (int*)malloc(sizeof(int)*(max_size+1));

	return temp;
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

	/*if (d->left > 0 && d->left <= (d->max_size - 1))
		d->left--;
	else if (d->left == 0)
		d->left = d->max_size - 1;
	else {
		printf("Error!");
		exit(0);
	}*/

	d->left = --d->left % d->max_size;

	d->dequeue[d->left] = item;

	return;


}
void PushRight(Dequeue *d, int item)
{
	if (IsFullDequeue(d)) {
		printf("Dequeue is full!\n");
		return;
	}

	d->dequeue[d->right] = item;

	/*if (d->right >= 0 && d->right < (d->max_size - 1))
		d->right++;
	else if (d->right == (d->max_size - 1))
		d->right = 0;
	else {
		printf("Error!");
		exit(0);
	}*/

	d->right = ++d->right % d->max_size;

	return;

}
int PopLeft(Dequeue *d)
{
	int temp = 0;

	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}

	temp = d->dequeue[d->left];

	/*if (d->left >= 0 && d->left < (d->max_size - 1))
		d->left++;
	else if (d->left == (d->max_size - 1))
		d->left = 0;
	else {
		printf("Error!");
		exit(0);
	}*/

	d->left = ++d->left % d->max_size;

	return temp;
}
int PopRight(Dequeue *d)
{
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}

	/*if (d->right > 0 && d->right <= (d->max_size - 1))
		d->right--;
	else if (d->right == 0)
		d->right = (d->max_size - 1);
	else {
		printf("Error!");
		exit(0);
	}*/

	d->right = --d->right % d->max_size;

	return d->dequeue[d->right];
}
int IsFullDequeue(Dequeue *d)		// if d is full, return 1, otherwise, 0
{
	/*if (d->right != (d->max_size - 1)) {
		if (d->right + 1 == d->left)
			return 1;
	}
	else if (d->right == (d->max_size - 1)) {
		if (d->left == 0)
			return 1;
	}*/

	if ((d->right+1) % d->max_size == d->left)
		return 1;
	
	return 0;
}
int IsEmptyDequeue(Dequeue *d)		// if d is empty, return 1, otherwise, 0
{
	/*if (d->right == d->left) {
		return 1;
	}*/

	if (d->right == d->left)
		return 1;

	return 0;
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
			printf("    ");
		for (; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
	}
	else {
		for (i = 0; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
		for (; i < d->left; i++)
			printf("    ");
		for (; i < d->max_size; i++)
			printf("%3d ", d->dequeue[i]);
	}

	printf("\n");
}


int main(void) {
	Dequeue *d = CreateDequeue(10);

	printf("PushRight(10)\n");
	PushRight(d, 10);

	for (int i = 0; i < 11; i++)
		PushRight(d, 10);

	DisplayDequeue(d);

	printf("PopLeft() returns %d\n", PopLeft(d));

	DisplayDequeue(d);

	DestroyDequeue(d);

	printf("Bye!\n");

	system("PAUSE");

	return 0;
}
