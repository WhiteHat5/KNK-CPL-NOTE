#include <stdio.h>
#define N 30


void read_line(char *sentence);
void reverse(char *message);

int main(void)
{
	char message[N];
	
	printf("Enter a message: ");
	read_line(message);
	
	reverse(message);
	printf("Reversal is: %s\n", message);
	
	return 0;
}

void read_line(char *sentence)
{
	while((*sentence++=getchar()) != '\n')
	;
	*--sentence = '\0';
}

void reverse(char *message)
{
	char *begin, *end, temp;
	begin = end = message;
	while(*end)
		*end++;
	end--; //end now points to the last character of the string
	
	while(begin < end){
		temp = *begin;
		*begin++ = *end;
		*end-- = temp;
	}
}