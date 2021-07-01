#include <stdio.h>

int main()
{
    int hour, min;
    
    printf("Enter a 24-hour time: ");
    scanf("%d :%d",&hour ,&min);
    printf("Equivalent 12-hour time: ");
    if(hour>=13)
    {
        printf("%d:%.2d PM",hour-12,min);
    }
    else if(hour>0)
    {
        printf("%d:%.2d AM",hour,min);
    }
    else
    {
        printf("12:%.2d PM",min);
    }

    return 0;
}
