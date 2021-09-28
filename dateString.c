#include <stdio.h>

int main(void)
{
	int month, day, year;
	
	char* month_name[] = {"January", "Feburary", "March", "April", 
						  "May", "June", "July", "August", 
						  "September", "October", "November", "December"};
	
	printf("Enter a date (mm/dd/yyyy): ");
	scanf("%d /%d /%d", &month, &day, &year);
	
	printf("You entered the date %s %d, %d\n", month_name[month-1], day, year);
	
	return 0;
}