#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

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
