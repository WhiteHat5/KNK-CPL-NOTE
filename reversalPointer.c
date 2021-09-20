#include <stdio.h>
#define N 30

int main(void)
{
	char message[N], ch;
	char *p = message;
	
	printf("Enter a message: ");
	while(p < message + N){
		if((ch=getchar()) != '\n')
			*p++ = ch;
		else
			break;
	}
	
	printf("Reversal is: ");
	while(p >= message){
		putchar(*p--);
	}
	putchar('\n');
	
	return 0;
}