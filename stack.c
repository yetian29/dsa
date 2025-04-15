#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	int capacity;
	int top;
	int *items;
} stack;

stack *initializeStack(int capacity)
{
	stack *s = malloc(sizeof(stack));
	if (!s)
	{
		fprintf(stderr, "Allocation memory for stack failed\n");
		exit(1);
	}
	s->items = malloc(capacity * sizeof(int));
	if (!s->items)
	{	
		fprintf(stderr, "Allocation memory for stack items failed\n");
		exit(1);
	}
	s->capacity = capacity;
	s->top = 0;
	return s;

}

bool isEmpty(stack *s)
{
	if (s->top == 0) return true;
	return false;
}

void push(stack *s, int data)
{
	// Stack is empty
	if (isEmpty(s))
	{
		s->items[s->top] = data;
		s->top++;
		return;
	}
	// Stack is full
	if (s->top == s->capacity)
	{
		s->capacity *= 2;
		s->items = realloc(s->items, sizeof(int) * (s->capacity));
	}
	// Stack has elements occupied 
	s->items[s->top] = data;
	s->top++;
}

void pop(stack *s)
{
	// Stack is empty
	if (isEmpty(s))
	{
		printf("Stack is empty\n");
		return;
	}
	// Stack has element occupied 
	s->top--;

}

void peek(stack *s, int position)
{
	if (position < 0 || position >= s->top)
	{
		fprintf(stderr, "Position outside range index of array\n");
		exit(1);
	}
  printf("%d\n", s->items[position]);
}

void out(stack *s)
{
	// Stack is empty
	if (isEmpty(s))
	{
		printf("Stack is empty\n");
		return;
	}
	printf("Size: %d, Capacity: %d\n", s->top, s->capacity);
	for (int i = 0; i < s->top; i++)
	{
		printf("%d", s->items[i]);
		if (i < s->top - 1) printf(" | ");
	}
	printf("\n");
}


void freeStack(stack *s)
{
	free(s->items);
	free(s);
}

int main(void)
{
	int capacity = 1;
	stack * s = initializeStack(1);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	push(s, 4);
	out(s);
	pop(s);
	out(s);
	peek(s, 2);
	peek(s, -1);
	freeStack(s);
	return 0;
}
