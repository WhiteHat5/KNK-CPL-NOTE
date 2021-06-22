#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int money;

	printf("ENTER DOLLAR AMOUNT: ");
	scanf("%d", &money);

	printf("$20 bills: %d\n", money / 20);
	money -= 20 * (money / 20);

	printf("$10 bills: %d\n", money / 10);
	money -= 10 * (money / 10);

	printf("$5 bills: %d\n", money / 5);
	money -= 5 * (money / 5);

	printf("$1 bills: %d\n", money);

	return 0;
}
