#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int digit1, digit2;

    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &digit1, &digit2);

    printf("You entered the number "); //begin the result-showing line

    switch (digit1)
    {
        case 1:
            switch (digit2)
            {
                case 0: printf("ten\n"); return 0;
                case 1: printf("eleven\n"); return 0;
                case 2: printf("twelve\n"); return 0;
                case 3: printf("thirteen\n"); return 0;
                case 4: printf("fourteen\n"); return 0;
                case 5: printf("fifteen\n"); return 0;
                case 6: printf("sixteen\n"); return 0;
                case 7: printf("seventeen\n"); return 0;
                case 8: printf("eighteen\n"); return 0;
                case 9: printf("nineteen\n"); return 0;
            }
        case 2: printf("twenty"); break;
        case 3: printf("thirty"); break;
        case 4: printf("fourty"); break;
        case 5: printf("fifty"); break;
        case 6: printf("sixty"); break;
        case 7: printf("seventy"); break;
        case 8: printf("eighty"); break;
        case 9: printf("ninety"); break;
        default:
            printf("Enter two digit number PLEASE!!!\n"); return 0;
    }

    switch (digit2)
    {
        case 0: break;
        case 1: printf("-one"); break;
        case 2: printf("-two"); break;
        case 3: printf("-three"); break;
        case 4: printf("-four"); break;
        case 5: printf("-five"); break;
        case 6: printf("-six"); break;
        case 7: printf("-seven"); break;
        case 8: printf("-eight"); break;
        case 9: printf("-nine"); break;
        default:
            printf("ERROR IN CODE\nSHUT DOWN IMMEDIATELY\n"); return 0;

    }

    return 0;
}
