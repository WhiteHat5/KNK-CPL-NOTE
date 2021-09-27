#include <stdio.h>

void read_line(char *sentence);
void reverse_name(char *name);

int main(void) {

    char name[40];

    printf("Enter a first and last name: ");
    read_line(name);
	reverse_name(name);
	puts(name);

    return 0;
}

void read_line(char *sentence)
{
	while((*sentence++=getchar()) != '\n')
	;
	*--sentence = '\0';
}

void reverse_name(char *name)
{
	char initial, *s = name;
	while(*s == ' ') s++;
	initial = *s;
	while(*s != ' ') s++;
	while(*s == ' ') s++;
	while((*name++ = *s++));
	*(--name) = '.'; *(++name) = ' '; *(++name) = initial; *(++name) = '\0';
}