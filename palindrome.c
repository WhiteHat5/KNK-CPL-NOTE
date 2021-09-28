#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define N 100

void read_line(char *sentence);
bool is_palindrome(const char *message);

int main(void)
{
	
	char message[N], ch;
	char *pos = message;
	
	printf("Enter a message: ");
	read_line(message);
	
	if(is_palindrome(message))
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}

void read_line(char *sentence)
{
	while((*sentence++=getchar()) != '\n') // sentence의 크기가 충분한지 검사하고 있지 않다
	;
	*--sentence = '\0';
}

bool is_palindrome(const char *message)
{
	const char *begin, *end;
	begin = end = message;
	while(*end)
		*end++;
	end--; //end now points to the last character of the string
	
	while(begin < end) {
		if ( ! isalpha(*begin))  { begin++; continue; }
		if ( ! isalpha(*end))    { end--;   continue; }
		if(tolower(*begin) != tolower(*end))
			return false;
		else {
			begin++; end--;
		}
	}
	
	return true;
}