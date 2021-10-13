#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct node {
	int value;
	struct node *next;
};

struct node *first = NULL;

bool push(int integer)
{	
	struct node *new_node;
    if ((new_node = malloc(sizeof(struct node))) == NULL)
        return false;
    else {
		new_node->value = integer;
		new_node->next = first;
		first = new_node;
	}
	return true;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else {
		int value;
		value = first->value;
		struct node *temp = first;
		first = first->next;
		free(temp);
		return value;
	}
        
}

bool is_empty(void)
{
    if(first == NULL)
		return true;
	else
		return false;
}

void stack_overflow(void)
{
    printf("STACK OVERFLOW\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("STACK UNDERFLOW\n");
    exit(1);
}

void print_result(void)
{
	int p;
    if (p = pop()){
        printf("Value of expression: ");
        printf("%d\n", p);
    }
    else {
        printf("Expression is too complex\n"); 
		make_empty();// clear stack
    }
}

void make_empty()
{
	struct node *temp;
	while(first != NULL) {
		temp = first;
		first = first->next;
		free(temp);
	}
}