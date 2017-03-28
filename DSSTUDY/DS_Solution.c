#include <stdio.h>

int main(void)
{
	int size = 10;
	int ary[10];
	int *ptr = NULL;
	int i = 0;

	for (i = 0; i < 100; i = (i+10)) {
		ary[i/10] = i;
	}	

	ptr = ary;

	printf("ary = %p, ary + 3 = %p, &ary[3] = %p \n", ary, ary + 3, &ary[3]);
	printf("ptr = %p, ptr + 3 = %p, &ptr[3] = %p \n", ptr, ptr + 3, &ptr[3]);

	printf("ary = { ");

	for (i = 0; i < 100; i = (i + 10)) {
		printf("%d, ", ary[i / 10]);
	}

	printf("}\n");

	return 0;
}