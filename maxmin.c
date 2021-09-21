# include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void)
{
	int b[N], *p, big, small;
	
	printf("Enter %d numbers: ", N);
	for(p = b; p < b + N; p++)
		scanf("%d", p);
	
	max_min(b, N, &big, &small);
	
	printf("Largest: %d\nSmallest: %d\n",big ,small);
	
	return 0;
}

void max_min(int a[], int n, int *max, int *min)
{
	int *p = a;
	
	*max = *min = *p;
	
	for(p++; p< a+n; p++){
		if(*p > *max)
			*max = *p;
		else if(*p < *min)
			*min = *p;
	}
}