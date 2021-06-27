#include <stdio.h>

int main()
{
    int var;
    printf("Enter a two-digit number: ");
    scanf("%d",&var);
    printf("The reversal is: %d",var/10 + var%10*10);
    
    return 0;
}
