#include <stdio.h>

int main()
{
    int var;
    printf("Enter a two-digit number: ");
    scanf("%d",&var);
    printf("The reversal is: %d",var/100 + var/10%10*10 + var%10*100);
    
    return 0;
}
