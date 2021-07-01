#include <stdio.h>

int main(void)
{
    int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,
        check, firstSum, secondSum, total;
    
    printf("Enter the 12 digits of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &check);
    firstSum = d + i2 + i4 + j1 + j3 + j5;
    secondSum = i1 + i3 + i5 + j2 + j4;
    total = 3 * firstSum + secondSum;

    printf(check == 9 - ((total-1)%10) ? "VALID" : "NOT VALID");

    return 0;
}
