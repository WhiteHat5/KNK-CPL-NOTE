#include <stdio.h>

int main()
{
    float n , big = 0.0f;
    
    do {
        printf("Enter a number: ");
        scanf("%f", &n);
        if (n > big)
            big = n;
    } while (n>0) ;
    
    printf("The largest number you entered was %.2f",big);
    return 0;
}
