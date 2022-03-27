#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int size;
	int *data;
	int top;
}stack;

bool is_stack_empty(stack *s);
bool is_stack_full(stack *s);
stack * stack_init(int size);
void stack_deinit(stack *s);
bool push(stack *s, int num);
int pop(stack *s);
void print_stack(stack *s);