#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main (void)
{
    int
    month1, month2,
    day1, day2,
    year1, year2;


    printf("Enter first date(mm/dd/yy): ");
    scanf("%d /%d /%d", &month1, &day1 ,&year1);
    printf("Enter second date(mm/dd/yy): ");
    scanf("%d /%d /%d", &month2, &day2 ,&year2);

    if (year1 > year2)
        {
            printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2, month1, day1, year1);
            return 0;
        }
    else if (year1 == year2)
        {
            if (month1 > month2)
                {
                printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2, month1, day1, year1);
                return 0;
                }
            else if (month1 == month2)
                {
                if (day1 > day2)
                    {
                    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month2, day2, year2, month1, day1, year1);
                    return 0;
                    }
                else if (day1 == day2)
                    {
                    printf("Same date!!\n");
                    return 0;
                    }
                }
                
        }
    printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", month1, day1, year1, month2, day2, year2);
    return 0;
}
