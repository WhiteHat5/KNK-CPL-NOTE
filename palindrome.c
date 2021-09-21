#include <stdio.h>
#include <ctype.h>
#define N 100

int main(void)
{
	
	char message[N], ch;
	char *pos = message;
	
	printf("Enter a message: ");
	while((ch=getchar()) != '\n'){
		if(isalpha(ch)){
			*pos++ = tolower(ch);
		}
		if(pos == message + N)
			break;
	}
	
	pos--;
	char *i = message; 
	
	while(i < pos){
		if(*i++ != *pos--){
			printf("Not a Palindrome\n");
			return 0;
		}
	}
	
	printf("Palindrome\n");
	return 0;
}