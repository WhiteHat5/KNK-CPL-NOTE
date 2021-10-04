#include <stdio.h>
#include "quicksort.h"

#define N 10

int main(void)
{
	int a[N], *p;
	
	printf("Enter %d numbers to be sorted: ", N);
	for(p = a; p < a + N; p++)
		scanf(" %d", p);
	quicksort(a, a, --p);
	
	printf("In sorted order: ");
	for(p = a; p < a + N; p++)
		printf("%d ", *p);
	printf("\n");
	
	return 0;
}

