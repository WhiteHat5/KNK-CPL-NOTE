/* Sums a series of numbers (using long variables) */

#include <stdio.h>

int main()
{
    double n, sum = 0.0;
    
    printf("This program sums series of floting-point numbers. \n");
    printf("Enter numbers (0 to terminate): ");
    
    scanf("%lf", &n);
    while (n != 0.0) {
        sum += n;
        scanf("%lf", &n);
    }
    
    printf("The sum is: %f\n", sum);
    
    return 0;
}
