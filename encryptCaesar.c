#include <stdio.h>

int main()
{
    char message[80];
    int shift
            ,i;
    
    //암호화할 원문 입력
    printf("Enter message to be encrypted: ");
    for(i=0; (message[i] = getchar()) != '\n'; i++)
    /*공백*/   ;
    
    //암호값 입력
    printf("Enter shift amount(1-25): ");
    scanf("%d", &shift);
    
    //암호문 출력
    printf("Encrypted message: ");
    for(i=0; message[i] != '\n'; i++){
        if(message[i] >= 'a' && message[i] <= 'z'){
            putchar(((message[i] - 'a' + shift)%26) + 'a');
        }
        else if(message[i] >= 'A' && message[i] <= 'Z'){
            putchar(((message[i] - 'A' + shift)%26) + 'A');
        }
        else
            putchar(message[i]);
    }
    
}
