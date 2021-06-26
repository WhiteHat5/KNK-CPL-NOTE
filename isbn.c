#include <stdio.h>

int main()
{
    int prefix, identifier, publisher, item, check;
    
    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d",&prefix,&identifier,&publisher,&item,&check);
    
    printf("GS1 prefix: %d\n",prefix);
    printf("Group identifier: %d\n", identifier);
    printf("Publisher Code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %d\n", check);
    

    return 0;
}
