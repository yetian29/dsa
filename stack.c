#include <stdio.h>
#include <stdlib.h>

#define capacity 5

typedef struct 
{
	int top;
	int items[capacity];
} stack;

void initializeStack(stack *s)
{
	s->top = -1;
}

void push(stack *s, int data)
{
	// Stack is full
	if (s->top == capacity - 1)
	{
		fprintf(stderr, "Overflow\n");
		exit(1);
	}
	s->top++;
	s->items[s->top] = data;
}

void pop(stack *s)
{
	// Stack is empty
	if (s->top < 0)
	{
		fprintf(stderr, "Underflow\n");
		exit(1);
	}
	s->top--;
}

void out(stack *s)
{
	printf("Top: %d\n", s->top);
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
	initializeStack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	push(&s, 5);
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
