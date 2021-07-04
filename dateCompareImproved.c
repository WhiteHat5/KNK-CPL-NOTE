#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main (void)
{
    int 
    month, emonth = 12,
    day, eday = 31,
    year, eyear = 99; // 가장 빠른 날짜를 비교하기 위해 기본값을 가능한 날짜 중 가장 뒤에 있는 날짜로 설정했다

    for(;;){
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d /%d /%d", &month, &day, &year);

        if(month == 0){
            printf("\n%d/%d/%.2d is the earliest date\n", emonth, eday, eyear);
            break;
        }

        if (year > eyear){
            continue;
        }
        else if (year == eyear){
            if (month > emonth){
                continue;
            }
            else if (month == emonth){
                if (day > eday){
                    continue;
                }
                else if (day == eday){
                    continue;
                }
            }
                
        }
    eyear = year; emonth = month; eday = day;

    }

    return 0;
}
