#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

bool push(int);
int pop(void);
bool is_empty(void);
void stack_overflow(void);
void stack_underflow(void);
void print_result(void);
void make_empty(void);

#endif