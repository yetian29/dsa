#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5


typedef struct
{
	int top;
	int items[size];
} stack;

void initialize(stack *s)
{
	s->top = -1;
}

bool isFull(stack *s)
{
	return s->top == size - 1;
}

bool isEmpty(stack *s)
{
	return s->top == -1;
}

void push(stack *s, int x)
{
	// Stack is full
	if (isFull(s))
	{
		fprintf(stderr, "Overflow\n");
		exit(1);
	}
	s->top++;
	s->items[s->top] = x;
}

void pop(stack *s)
{
	// Stack is empty
	if (isEmpty(s))
	{
		fprintf(stderr, "Underflow\n");
		exit(1);
	}
	s->top--;
}

void out(stack *s)
{
	for (int i = s->top; i >= 0; i--)
	{
		printf("%d", s->items[i]);
	  if (i > 0) printf(" | ");
	}
	printf("\n");
}

int main(void)
{
	stack s;
	initialize(&s);
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
	pop(&s);
	out(&s);
	return 0;
}
