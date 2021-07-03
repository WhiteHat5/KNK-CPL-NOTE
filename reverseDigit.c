#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter a positive number: ");
    scanf("%d", &num);
    printf("The reversal is ");
    do {
        printf("%d",num%10);
        num /= 10;
    } while (num != 0);

    return 0;
}
