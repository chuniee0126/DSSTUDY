#include <stdio.h>
#include <malloc.h>

#define MAX_SIZE 256

typedef struct
{
	int month, date, hour, min;
	char title[256];

}Plan;

void buffer(void) {
	while (getchar() != '\n');
}


int main(void)
{
	int repeat = 0, i = 0;
	Plan * pnt;

	printf("# of schedules: ");
	scanf("%d", &repeat);

	pnt = (Plan *)malloc(sizeof(Plan) * repeat);

	buffer();

	for (i = 0; i < repeat; i++) {
		printf("%d-th schedule: \n", i);
		printf("	date (month date): ");
		scanf("%d %d", &pnt[i].month, &pnt[i].date);
		printf("	time (hour min): ");
		scanf("%d %d", &pnt[i].hour, &pnt[i].min);
		buffer();
		printf("	title: ");
		fgets(pnt[i].title, MAX_SIZE, stdin);
		/*scanf 로 가능한 방법*/
		//scanf("%[^\n]s", pnt[i].title);
	}

	printf("=== %d schedules ===\n", i);

	for (i = 0; i < repeat; i++) {
		printf("%d %d, %d:%d, %s \n", pnt[i].month, pnt[i].date, pnt[i].hour, pnt[i].min, pnt[i].title);
	}

	free(pnt);

	return 0;
}