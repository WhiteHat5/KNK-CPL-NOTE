#include <stdio.h>

int main()
{
    int hour, min;
    
    printf("Enter a 24-hour time: ");
    scanf("%d :%d",&hour ,&min);
    printf("Equivalent 12-hour time: ");
    
    if (hour>=12)
    {
        printf("%2d:%.2d PM",hour == 12 ? 12 : hour-12 , min);
    }
    else
    {
        printf("%2d:%.2d", hour == 0 ? 12 : hour, min);
    }

    return 0;
}
