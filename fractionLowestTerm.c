#include <stdio.h>

int main()
{
    int denom , num , rem,m,n;
    
    printf("Enter afraction: ");
    scanf("%d /%d", &denom, &num);
    m = denom; n = num;
    while (n!=0){
        rem = m%n;
        m = n;
        n = rem;
    }
    
    printf("In lowest terms: %d/%d",denom/m ,num/m);
    
    return 0;
}
