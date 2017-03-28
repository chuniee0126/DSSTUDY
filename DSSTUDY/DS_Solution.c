#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int size = 10;
	int *ptr = NULL;
	int i = 0;

	ptr = (int *)malloc(sizeof(int) * size);
	for (i = 0; i < 100; i = i + 10) {
		*(ptr + i / 10) = i;
	}

	printf("ptr = %p, ptr + 3 = %p, &ptr[3] = %p \n", ptr, ptr + 3, &ptr[3]);

	for (i = 0; i < size; i++) {
		printf(" %d ", ptr[i]);
	}

	printf("\n");

	free(ptr);

	return 0;
}