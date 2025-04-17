#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define capacity 5

typedef struct 
{
	int top;
	int size;
	int items[capacity];
} stack;

void initializeStack(stack *s)
{
	s->top = 0;
	s->size = capacity;
}

bool isEmpty(stack *s)
{
	if (s->top == 0) return true;
	return false;
}

void push(stack *s, int data)
{
	// Stack is full
	if (s->top == s->size)
	{
		fprintf(stderr, "Overflow\n");
		exit(1);
	}
	s->items[s->top] = data;
	s->top++;
}

void pop(stack *s)
{
	if (isEmpty(s))
	{
		fprintf(stderr, "Underflow\n");
		exit(1);
	}
	s->top--;
}

void out(stack *s)
{
	for (int i = 0; i < s->top; i++)
	{
		printf("%d", s->items[i]);
		if (i < s->top - 1) printf(" | ");
	}
	printf("\n");
}


int main(void)
{
	stack s;
	initializeStack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	/*push(&s, 6);*/
	out(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	pop(&s);
	/*pop(&s);*/
	out(&s);

	return 0;
}
