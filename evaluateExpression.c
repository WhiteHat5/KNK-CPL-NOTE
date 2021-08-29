#include <stdio.h>

int main()
{
    float result = 0 , temp;
    char sign;
    
    printf("Enter an expression: ");
    scanf(" %f", &temp);
    result = temp;
    
    while((sign=getchar())!='\n') {
        
        switch(sign){
            case '+':
                scanf("%f", &temp);
                result += temp;
                break;
            case '-':
                scanf("%f", &temp);
                result -= temp;
                break;
            case '*':
                scanf("%f", &temp);
                result *= temp;
                break;
            case '/':
                scanf("%f", &temp);
                result /= temp;
                break;
            default:
                break;
        }
    }
    
    printf("Value of expression: %g\n", result);

    return 0;
}
