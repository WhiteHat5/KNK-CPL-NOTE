#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool are_anagrams(const char *word1, const char *word2);
void read_word(char *word);

int main()
{
	char word1[20], word2[20];
	
	printf("Enter first word: ");
	read_word(word1);
	printf("Enter second word: ");
	read_word(word2);
	
	if(are_anagrams(word1, word2))
		printf("The words are anagrams\n");
	else
		printf("The words are not anagrams\n");

    return 0;
}

void read_word(char *word)
{
	while(isalpha(*word++ = getchar()))
	;
	*--word = '\0';
}

bool are_anagrams(const char *word1, const char *word2)
{
	int seen[26] = {0};
	while(*word1)
		seen[tolower(*(word1++)) - 'a']++;
	while(*word2)
		seen[tolower(*(word2++)) - 'a']--;
	
	for(int i=0; i<26; i++)
		if(seen[i] != 0)
			return false;
	return true;
}