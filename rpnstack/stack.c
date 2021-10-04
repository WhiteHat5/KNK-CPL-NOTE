#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

#define STACK_SIZE 100

int integers[STACK_SIZE];
int top = 0;

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