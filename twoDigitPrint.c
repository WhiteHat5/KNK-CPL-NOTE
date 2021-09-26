#include <stdio.h>

int main(void) {

    int n;
	char* first_digit[] = {"twenty", "thirty", "fourty", "fifty",
						   "sixty", "seventy", "eighty", "ninety"};
	char* second_digit[] = {"one", "two", "three", "four", "five",
						    "six", "seven", "eight", "nine"};
	char* teen[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
				    "sixteen", "seventeen", "eighteen", "nineteen"};
	
    printf("Enter a two-digit number: ");
    scanf("%d", &n);
	printf("You entered the number ");
	if (n/10 == 1)
		printf ("%s\n", teen[n%10]);
	else if(n%10)
		printf("%s-%s\n",first_digit[n/10 -2], second_digit[n%10 -1]);
	else
		printf("%s\n", first_digit[n/10 -2]);
	

    return 0;
}