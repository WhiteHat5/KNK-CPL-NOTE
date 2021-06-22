#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

float MothlyPayment(float bal, float inte, float pay)
{
	
	bal *= (100 + inte / 12) / 100;
	bal -= pay;
	return bal;
}
int main(void)
{
	float balance, interest, payment;
	printf("Enter amount of loan: ");
	scanf("%f", &balance);
	printf("Enter interest rate: ");
	scanf("%f", &interest);
	printf("Enter monthly payment: ");
	scanf("%f", &payment);

	balance = MothlyPayment(balance, interest, payment);
	printf("Balance after first payment: $%.2f\n", balance);
	balance = MothlyPayment(balance, interest, payment);
	printf("Balance after second payment: $%.2f\n", balance);
	balance = MothlyPayment(balance, interest, payment);
	printf("Balance after third payment: $%.2f\n", balance);

	return 0;
}
