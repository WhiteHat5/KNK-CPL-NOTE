#include <stdio.h>

void encrypt(char *message, int shift);

int main()
{
    char message[80];
    int shift, i;
    
    //암호화할 원문 입력
    printf("Enter message to be encrypted: ");
    for(i=0; (message[i] = getchar()) != '\n'; i++)
    /*공백*/   ;
	message[i] = '\0'; //string 종료표시
    
    //암호값 입력
    printf("Enter shift amount(1-25): ");
    scanf("%d", &shift);
	
	//암호화
	encrypt(message, shift);
    
    //암호문 출력
    printf("Encrypted message: %s", message);
    
	return 0;
    
}

void encrypt(char *message, int shift)
{
	while(*message) {
		if(*message >= 'a' && *message <= 'z')
			*message = ((*message - 'a' + shift)%26) + 'a';
		else if(*message >= 'A' && *message <= 'Z')
			*message = ((*message - 'A' + shift)%26) + 'A';
		
		//알파벳이 아닐 경우 무시
		
		message++;
	}
}

//e.g. Jr dkhdg, pdnh pb gdb. // 23 //  Go ahead, make my day.