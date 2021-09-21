#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_SIZE 100

int integers[STACK_SIZE];
int top = 0;

void push(int);
int pop(void);
bool is_empty(void);
void stack_overflow(void);
void stack_underflow(void);
void print_result(void);
void analyze_expression(char);

int main(void){
    char ch;
    for(;;){
        printf("Enter an RPN expression: ");
        do{
            scanf(" %c", &ch);
            analyze_expression(ch);
        } while(ch != '=');
        print_result();
    }
}

void push(int integer)
{
    if (top == STACK_SIZE)
        stack_overflow();
    else
        integers[top++] = integer;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return integers[--top];
}

bool is_empty(void)
{
    return (top == 0);
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
    if (top == 1){
        printf("Value of expression: ");
        printf("%d\n", pop());
    }
    else {
        printf("Expression is too complex\n");
        top = 0; // clear stack
    }
}

void analyze_expression(char ch)
{
    int first,second;
    if(ch >= '0' && ch <= '9')
        push ((int)(ch - '0'));
    else switch(ch){
        case '+': 
            second = pop(); first = pop();
            push(first + second);
            break;
        case '*':
            second = pop(); first = pop();
            push(first * second);
            break;
        case '-':
            second = pop(); first = pop();
            push(first - second);
            break;
        case '/':
            second = pop(); first = pop();
            push(first / second);
            break;
        default: 
            if(ch != '='){
                printf("INVALID INPUT CHARACTER DETECTED \"%c\"\nPROGRAM TERMINATES\n", ch);
                exit(0);
            }
    }
}
