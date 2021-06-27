#include <stdio.h>

int main(void)
{
    int d,i1,i2,i3,i4,i5,j1,j2,j3,j4,j5,j6,
        firstSum, secondSum, total;
    
    printf("Enter the first 12 digits of a EAN: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d",&d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &j6);
    
    firstSum = i1 + i3 + i5 + j2 + j4 +j6;
    secondSum = d + i2 + i4 + j1 + j3 + j5;
    
    total = 3 * firstSum + secondSum;

    printf("Check digit : %1d\n",9 - ((total-1)%10));

    return 0;
}
