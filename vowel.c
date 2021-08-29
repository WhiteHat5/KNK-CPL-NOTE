#include <stdio.h>

int main()
{
    char temp;
    int cnt=0;
    
    printf("Enter a sentence: ");
    
    while(1)    {
        scanf("%c",&temp);
        switch(temp){
            case 'a': case 'A': 
            case 'e': case 'E': 
            case 'i': case 'I': 
            case 'o': case 'O':
            case 'u': case 'U':
                cnt++;
                break;
            default:
                break;
        }
        if(temp== '\n')
            break;
    }
    
    printf("Your sentence contains %d vowels\n", cnt);

    return 0;
}
