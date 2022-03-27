/*
	This file for stack functions
bool is_stack_empty(stack *s);
bool is_stack_full(stack *s);
stack * stack_init(int size);
void stack_deinit(stack *s);
bool push(stack *s, int num);
int pop(stack *s);
void print_stack(stack *s);
*/


#include "include/stack.h"

bool is_stack_empty(stack *s) {
	if (s->top == 0)
		return true;
	return false;
}

bool is_stack_full(stack *s) {
	if (s->top == s->size)
		return true;
	return false;
}

stack * stack_init(int size) {
	stack *s = malloc(sizeof(stack));
	s->size = size;
	s->top = 0;
	s->data = malloc(sizeof(int)*size);
	return s;
}

void stack_deinit(stack *s) {
	free(s->data);
	free(s);
}

bool push(stack *s, int num) {
	if(is_stack_full(s)) {
		printf("STACK is FULL ...\n");
		return false;
	}
	s->data[s->top] = num;
	s->top++;
	return true;
}

int pop(stack *s) {
	if(is_stack_empty(s)) {
		printf("STACK is Empty ...\n");
		return false;
	}
	s->top--;
	return s->data[s->top];
}
void print_stack(stack *s) {
	printf("Stack:");
	for(int i = 0; i < s->size; i++) {
		printf(" %d", s->data[i]);
	}
	printf("\n");
}

int main()
{
	stack *s;
	s = stack_init(5);
	push(s, 2);
	push(s, 5);
	push(s, 7);
	push(s, 8);
	push(s, 7);
	print_stack(s);
	
	printf("POP:%d\n", pop(s));
	printf("POP:%d\n", pop(s));
	printf("POP:%d\n", pop(s));
	printf("POP:%d\n", pop(s));
	printf("POP:%d\n", pop(s));
	printf("POP:%d\n", pop(s));
	
	stack_deinit(s);
	return 0;
}

