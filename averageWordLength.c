#include <stdio.h>

double compute_average_word_length(const char *sentence);
void read_line(char *sentence);

int main(void)
{
	char user_input[50];
	
    printf("Enter a sentence: ");
	read_line(user_input);
	printf( "Average word length: %.1f\n" , compute_average_word_length(user_input) );
	
    return 0;
}

void read_line(char *sentence)
{
	while((*sentence++=getchar()) != '\n')
	;
	*--sentence = '\0';
}

double compute_average_word_length(const char *sentence)
{
	int words = 1, length = 0;
	
	while(*sentence) {
		if (*sentence == ' ')
			words++;
		else 
			length++;
		sentence++;
	}
	
	return (double)length/words;
	
}