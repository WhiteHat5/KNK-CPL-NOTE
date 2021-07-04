#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	float balance, interest, payment, number;
	printf("Enter amount of loan: ");
	scanf("%f", &balance);
	printf("Enter interest rate: ");
	scanf("%f", &interest);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);
	printf("Enter number of payment: ");
	scanf("%f", &number);

	for(int i = 0; i<number; i++){
		balance = balance * (100.0f + interest / 12.0f) / 100.0f - payment;
		printf("Balance after payment: $%.2f\n", balance);
	}

	return 0;
}
