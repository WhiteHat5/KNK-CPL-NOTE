#include <stdio.h>

int main()
{
    float commision, pricePerShare, value;
    int share;
    
    printf("Enter the number of shares: ");
    scanf("%d",&share);
    printf("Enter the price per share: ");
    scanf("%f", &pricePerShare);
    value = share * pricePerShare;
    
    if (value < 2500.00f)
        commision = 30.00f + 0.17f * value;
    else if (value < 6250.00f)
        commision = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commision = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commision = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commision = 155.00f + .0011f * value;
    else
        commision = 255.00f + .0009f * value;
        
    if (commision < 39.00f)
        commision = 39.00f;
    printf("Original broker's commision: $%.2f\n", commision);
    
    if (share<2000)
        commision = 33.00f + .03f * share;
    else 
        commision = 33.00f + .02f * share;
    printf("New broker's commision: $%.2f\n", commision);
    

    return 0;
}
