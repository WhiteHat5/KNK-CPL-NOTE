#include <stdio.h>
#define N 100

int main()
{
    char terminating_character;
    char sentence[N];
    const char charset[3] = {'.' , '!', '?'};
    char *p = sentence, *q;
    
    printf("Enter a sentence: ");
	
	while((*p = getchar()) != '.' && *p != '!' && *p != '?')
	{
		if(p == sentence + N){
			printf("Too long\n");
			return 0;
		}
		p++;
	}
	
	terminating_character = *p;
    
    printf("Reversal of sentence: ");
    
	while(p >= sentence)
	{
		
		while(*(--p) != ' '){
			if(p == sentence)
				break;
		} //go front until it meets blank-character
		if (p == sentence){
			while(*p != ' ')
				putchar(*p++);
			break;
		}
		else{
			q = p++; //q is the position of the blank just before the word about to be printed
			while(*p != terminating_character && *p != ' ')
				putchar(*p++); 
			putchar(' ');
			p = q;
	}
		}
		

    putchar(terminating_character);
	putchar('\n');
    return 0;
}
