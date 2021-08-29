#include <stdio.h>

int main()
{
    int num1, denom1, num2, denom2, resultNum, resultDenom;
    char oper;
    
    printf("Enter two fractions separated by an operator sign(+,-,*,/): ");
    scanf("%d /%d%c%d /%d",&num1, &denom1, &oper, &num2, &denom2);
    
    switch(oper){
        case '+':
            printf("The sum is %d/%d",num1*denom2+num2*denom1,denom1*denom2);
            break;
        case '-':
            printf("The difference is %d/%d",num1*denom2-num2*denom1,denom1*denom2);
            break;
        case '*':
            printf("The product is %d/%d",num1*num2, denom1*denom2);
            break;
        case '/':
            printf("The quotient is %d/%d",num1*denom2, num2*denom1);
            break;
        default:
            printf("Invalid input\n");
            break;
            
    }
    
    

    return 0;
}

