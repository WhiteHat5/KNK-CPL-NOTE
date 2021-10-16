#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_WORD_LENGTH 20
#define MAX_WORD_NUM 50

char *stored_words[MAX_WORD_NUM];
int num_words = 0;

void print_word(void);
int compare_word(const void *a, const void *b);

int main(void)
{
	char input_word[MAX_WORD_LENGTH + 1]; //20글자보다 긴 단어는 고려하지 않음
	for(;;) {
		if(num_words == MAX_WORD_NUM) {
			printf("Max number of input words\n");
			break;
		}
		printf("Enter word: ");
		read_line(input_word, MAX_WORD_LENGTH + 1);
		if (strlen(input_word) == 0)
			break;
		stored_words[num_words] = malloc(strlen(input_word)+1);
		strcpy(stored_words[num_words], input_word);
		num_words++;
	}
	qsort(stored_words, num_words, sizeof(char *), compare_word);
	print_word();
	return 0;
}

void print_word(void)
{
	printf("\nIn sorted order: ");
	for(int i=0 ; i<num_words; i++) 
		printf("%s ", stored_words[i]);
	putchar('\n');
}

int compare_word(const void *a, const void *b)
{
	char *word1 = *(char **)a, *word2 = *(char**)b;
	return strcmp(word1,word2);
}