#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "line.h"

#define MAX_LINE_LEN 60

struct words{
	char word[MAX_WORD_LEN+2];
	struct words *next;
} *line = NULL;

int line_len = 0;
int num_words = 0;
bool more_space_toggle = false;

void clear_line(void) {
	struct words *prev, *cur = line;
	
	if(cur == NULL)
		return;
	if(cur->next == NULL) {
		free(cur);
	}
	else{
		while(cur != NULL) {
			prev = cur; cur = cur->next;
			free(prev);
		}
	}
	line = NULL;
	num_words = 0;
	line_len = 0;
}

void add_word(const char *word) {

    struct words *new_word, *cur = line;
	if((new_word = malloc(sizeof(struct words))) == NULL) {
		printf("malloc failed\n");
		exit(EXIT_FAILURE);
	}
	strcpy(new_word->word, word);
    line_len += strlen(word);
	
	if(num_words == 0) {
		new_word->next = line;
		line = new_word;
	}
	else{
		while(cur->next != NULL)
			cur = cur->next;
		cur->next = new_word;
		new_word->next = NULL;
		line_len++; //공백 하나가 더 들어감
	}
		
    num_words++;
}

int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

void write_line(void) {

    int extra_spaces, spaces_to_insert, i, j;
    more_space_toggle = !more_space_toggle;
	struct words *cur;

    extra_spaces = MAX_LINE_LEN - line_len;
    for (cur = line; cur != NULL; cur = cur->next) {
        printf("%s", cur->word);
		spaces_to_insert = extra_spaces / (num_words);
        if (more_space_toggle && extra_spaces > 0) {
            spaces_to_insert++;
            more_space_toggle = !more_space_toggle;
        }
        for (j = 1; j <= spaces_to_insert + 1; j++)
            putchar(' ');
        extra_spaces -= spaces_to_insert;
        num_words--;
    }
    putchar('\n');
}

void flush_line(void) {
	struct words *cur = line;
    if (line_len > 0) 
		while(cur != NULL){
			printf("%s ",cur->word);
			cur = cur->next;
		}
}