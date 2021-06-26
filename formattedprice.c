#include <stdio.h>

int main()
{
    int item, month, day, year;
    float price;
    
    printf("Enter Item Number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d /%d /%d",&month, &day, &year);
    
    printf("\nItem\tUnit\tPurchase\n\tPrice\tDate\n%d\t$%6.2f\t%.2d/%.2d/%.4d",item,price,month,day,year);

    return 0;
}
