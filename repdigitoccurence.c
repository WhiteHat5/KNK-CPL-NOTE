
#include <stdio.h>

int main()
{
    int occurence[10] = {0};
    int digit;
    long n;
    
    printf("Enter a number: ");
    scanf(" %ld",&n);
    
    while(n>0){
        digit = n%10;
        occurence[digit]++;
        n/=10;
        
    }
    
    printf("Digit:     ");
    for(int i=0;i<10;i++){
        printf("%3d",i);
    }
    printf("\nOccurence: ");
    for(int i=0; i<10; i++){
            printf("%3d",occurence[i]);
    }
    return 0;
}
