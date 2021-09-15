#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/*external variables*/
char contents[STACK_SIZE];
int top;

/*function prototypes*/
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(char);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){
    char ch;
    
    make_empty(); //clear stack;
    
    printf("Enter parentheses and/or braces: ");
    while( (ch=getchar()) != '\n'){
        if(ch == '{' || ch == '(')
            push(ch);
        else if(ch == ')' && pop() == '(')
            continue;
        else if(ch == '}' && pop() == '{')
            continue;
        else{
            printf("Parentheses/braces are not neseted properly.\n");
            return 0;
        }
            
    }
    if(top == 0){
        printf("Parentheses/braces are nested properly\n");
        return 0;
    }
    else{
        printf("Parentheses/braces are not nested properly\n");
        return 0;
    }
}


void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void)
{
    printf("\nSTACK_OVERFLOW!!!\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("\nSTACK_UNDERFLOW!!!\n");
    exit(2);
}
