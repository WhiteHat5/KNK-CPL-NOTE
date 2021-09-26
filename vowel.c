#include <stdio.h>
#include <stdlib.h>

int compute_vowel_count(const char *sentence);
void read_line(char *sentence);

int main()
{
    char s[50];
    printf("Enter a sentence: ");
    read_line(s);
    printf("Your sentence contains %d vowels\n", compute_vowel_count(s));

    return 0;
}

int compute_vowel_count(const char *sentence)
{
	int cnt = 0;
	while(*sentence) {
		switch(*sentence++) {
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
	}
	
	return cnt;
}

void read_line(char *sentence)
{
	while((*sentence++=getchar()) != '\n')
	;
	*sentence = '\0';
	
}