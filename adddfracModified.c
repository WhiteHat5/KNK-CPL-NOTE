#include <stdio.h>

int main()
{
    int num1, denom1, num2, denom2, resultNum, resultDenom;
    
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d /%d +%d /%d",&num1, &denom1, &num2, &denom2);
    printf("The sum is %d/%d",num1*denom2+num2*denom1,denom1*denom2);
    

    return 0;
}
