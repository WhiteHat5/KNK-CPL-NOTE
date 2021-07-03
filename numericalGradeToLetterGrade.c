#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int grade, fdigit;

    printf("Enter numerical grade: ");
    scanf("%d", &grade);

    if (grade>100 || grade<0)
        {
            printf("Enter the grade within range of 0-100\n");
            printf("Enter numerical grade: ");
            scanf("%d", &grade);
        }
    
    fdigit = grade/10;
    if (grade == 100)
        printf("Letter grade: A\n");
    else
    {
        switch (fdigit) 
        {
            case 9:
                printf("Letter grade: A\n");
                break;
            case 8:
                printf("Letter grade: B\n");
                break;
            case 7:
                printf("Letter grade: C\n");
                break;
            case 6:
                printf("Letter grade: D\n");
                break;
            default:
                printf("Letter grade: F\n");
                break;
            
        }
    }

    return 0;
}
