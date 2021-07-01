#include <stdio.h>

int main()
{
    float income;
    
    printf("Enter the amount of taxable income: ");
    scanf("%f", &income);
    
    printf("The amount of tax due is: $");
    
    if (income < 750)
        printf("%.2f", income/100.0f);
    else if (income < 2250)
        printf("%.2f", 7.50f + (income-750.00f)* 2.00f / 100.00f);
    else if (income < 3750)
        printf("%.2f", 37.50f + (income - 2250.00f) * 3.00f / 100.00f);
    else if (income < 5250)
        printf("%.2f", 82.50f + (income - 3750) * 4.00f / 100.00f);
    else if (income <7000)
        printf("%.2f", 142.50f + (income - 5250.00f) * 5.00f / 100.00f);
    else
        printf("%.2f", 230.00f + (income - 7000.00f) * 6.00f / 100.00f);
    return 0;
}
