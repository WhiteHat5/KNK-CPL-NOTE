#include <stdio.h>
#include <math.h>

int main()
{
    
    double x,y=1.0,average;
    
    printf("Enter a positive number: ");
    scanf(" %lf", &x);
    
    while(fabs(y-(average = (y+x/y)/2)) > 0.00001*y){
        y=average;
    }
    
    printf("Square root: %f\n",y);
    
    
    return 0;
}
