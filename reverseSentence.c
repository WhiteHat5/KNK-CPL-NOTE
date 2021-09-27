#include <stdio.h>
#define MAX_WORDS_NUM 30
#define MAX_WORDS_LENGTH 20

int read_word(char word[MAX_WORDS_NUM][MAX_WORDS_LENGTH], char* t_char);
void print_reversal(char word[MAX_WORDS_NUM][MAX_WORDS_LENGTH], int word_num);

int main()
{
    char terminating_character, *t_char = &terminating_character;
    char words[MAX_WORDS_NUM][MAX_WORDS_LENGTH];
    int word_num;
	
    printf("Enter a sentence: ");
	word_num = read_word(words, t_char);
    
    printf("Reversal of sentence: ");
    print_reversal(words, word_num);
		
	putchar(terminating_character); putchar('\n');
	
    return 0;
}

int read_word(char word[MAX_WORDS_NUM][MAX_WORDS_LENGTH], char* t_char)
{
	int i,j;
	for(i = 0; i < MAX_WORDS_NUM; i++){
		for(j = 0; j < MAX_WORDS_LENGTH; j++){
			*t_char=getchar();
			if(*t_char == '.' || *t_char == '!' || *t_char == '?'){
				word[i][j] = '\0';
				goto END;
			}else if(*t_char == ' ') {
				word[i][j] = '\0';
				break;
			}else
				word[i][j] = *t_char;
		}
	} 
	END:
	return i;
}

void print_reversal(char word[MAX_WORDS_NUM][MAX_WORDS_LENGTH], int word_num)
{
	while(word_num >= 0) {
		printf("%s",word[word_num--]);
		if (word_num >= 0)
			putchar(' ');
	}
	
}
