#include "Dequeue2.h"
#include <stdio.h>
#include <malloc.h>


Dequeue *CreateDequeue(int max_size) {
	Node *temp = (Node*)malloc(sizeof(Node));
	Dequeue *d = (Dequeue*)malloc(sizeof(Dequeue));

	temp->data = NULL;
	temp->llink = NULL;
	temp->rlink = NULL;

	d->left = temp;
	d->right = temp;
	
	return d;
}
void DestroyDequeue(Dequeue *d) {
	Node * p = d->right;
	Node * temp = NULL;

	while (p != NULL)
	{
		temp = p->llink;
		free(p);
		p = temp;
	}

	free(d);

	return;
}

void PushLeft(Dequeue *d, int item) {
	Node * p = d->left;
	Node * nd = (Node*)malloc(sizeof(Node));

	nd->data = item;
	nd->rlink = p;
	p->llink = nd;

	d->left = nd;

	return;
}
void PushRight(Dequeue *d, int item) {
	Node * p = d->right;
	Node * nd = (Node*)malloc(sizeof(Node));

	nd->data = item;
	nd->llink = p;
	p->rlink = nd;

	d->right = nd;

	return;
}
int PopLeft(Dequeue *d){
	Node * p = d->left;
	int temp = p->data;
	
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is Empty! \n");
		return;
	}

	d->left = p->rlink;
	free(p);

	return temp;
}
int PopRight(Dequeue *d){
	Node * p = d->right;
	int temp = p->data;

	if (IsEmptyDequeue(d)) {
		printf("Dequeue is Empty! \n");
		return;
	}

	d->left = p->llink;
	free(p);

	return temp;
}
int IsFullDequeue(Dequeue *d){

}
int IsEmptyDequeue(Dequeue *d){

	if (d->right == NULL && d->left == NULL)
		return 1;
	else
		return 0;
}

void DisplayDequeue(Dequeue *d){
	Node * p = NULL;
	int n = 0;

	if (IsEmptyDequeue(d)) {
		printf("Dequeue is Empty! \n");
		return;
	}

	for (p = d->left; p != NULL; p = p->rlink, n++)
		printf("%3d", p->data);

	printf(" (%d items)\n", n);
}
void DisplayDequeueReverse(Dequeue *d){
	Node * p = NULL;
	int n = 0;

	if (IsEmptyDequeue(d)) {
		printf("Dequeue is Empty! \n");
		return;
	}

	for (p = d->right; p != NULL; p = p->llink, n++)
		printf("%3d", p->data);

	printf(" (%d items)\n", n);
}