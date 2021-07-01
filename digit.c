#include <stdio.h>

int main()
{
    int num, digit;
    
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num<0)
    {
        printf("The number is not in range");
    }
    else if(num<10)
    {
        digit = 1;
    }
    else if(num<100)
    {
        digit = 2;
    }
    else if (num<1000)
    {
        digit = 3;
    }
    else 
    {
        digit = 4;
    }
    printf("The number %d has %d digits",num,digit);

    return 0;
}
