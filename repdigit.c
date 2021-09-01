#include <stdbool.h>
#include <stdio.h>

int main()
{
    bool digit_seen[10][2] = {{false},{false}};
    int digit;
    long n;
    
    printf("Enter a number: ");
    scanf(" %ld",&n);
    
    while(n>0){
        digit = n%10;
        if(digit_seen[digit][0])
            digit_seen[digit][1] = true;
        else
            digit_seen[digit][0] = true;
        n/=10;
        
    }
    
    printf("Repeated digit(s): ");
    for(int i=0; i<10; i++){
        if(digit_seen[i][1]){
            printf(" %d",i);
        }
    }
    return 0;
}
