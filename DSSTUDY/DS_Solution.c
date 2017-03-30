#include <stdio.h>
#include <math.h>


int RecursiveSearch(int arr[], int size, int target)
{

	if (size == 0)
		return -1;
	else if (size > 0 && arr[size - 1] == target)
		return size - 1;
	else
		return RecursiveSearch(arr, size - 1, target);

}

int main(void)
{
	int arr[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int size = 10;
	int target = 0, result = 0;
	int i = 0, j = 0, temp;

	srand(time(NULL));

	printf("array = ");

	for (i = 0; i < size; i++) {
		j = rand() % 10;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	while (1) {
		printf("input integer : ");

		scanf("%d", &target);

		printf("searching %d...result = ", target);

		result = RecursiveSearch(arr, size, target);

		printf("%d \n", result);

		if (result == -1)
			break;
		
	}

	return 0;
}