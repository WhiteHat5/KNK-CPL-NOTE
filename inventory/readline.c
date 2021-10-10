#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
	int ch, i=0;
	
	while (isspace(ch=getchar()))
		; //처음에 나오는 공백문자를 스킵
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}