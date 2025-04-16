#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	int capacity;
	int head;
	int tail;
	int *items;
} buffer;

buffer *initializeBuffer(int capacity)
{
	buffer *b = malloc(sizeof(buffer));
	if (!b)
	{
		fprintf(stderr, "Allocation memory for buffer failed\n");
		exit(1);
	}
	b->items = malloc(capacity * sizeof(int)); // Note: only (capacity - 1) elements can be stored at a given time
	if ( !(b->items) )
	{
		fprintf(stderr, "Allocation memory for buffer items failed\n");
		exit(1);
	}
	b->head = 0;
	b->tail = 0;
	b->capacity = capacity;
	return b;
}

bool isFull(buffer *b)
{
	if ( ((b->tail) + 1) % (b->capacity) == (b->head) ) return true;
	return false;
}

bool isEmpty(buffer *b)
{
	if (b->head == b->tail) return true;
	return false;
}

void enqueue(buffer *b, int data)
{
	// Buffer is full, avoid overflow
	if (isFull(b))
	{
		fprintf(stderr, "Buffer is full\n");
		exit(1);
	}
	b->items[b->tail] = data;
	b->tail = (b->tail + 1) % (b->capacity);
}

void dequeue(buffer *b)
{
	if (isEmpty(b))
	{
		fprintf(stderr, "Buffer is empty\n");
		exit(1);
	}
	b->head = (b->head + 1) % (b->capacity);
}


void out(buffer *b)
{
	printf("Head: %d, Tail: %d, Capacity: %d\n", b->head, b->tail, b->capacity);
	if (isEmpty(b))
	{
		printf("Buffer is empty\n");
		return;
	}
	int i = b->head;
	while (i != b->tail)
	{
		printf("%d", b->items[i]);
		i = (i + 1) % (b->capacity);
		if (i != b->tail) printf(" | ");	
	}

	printf("\n");
	


}

void freeBuffer(buffer *b)
{
	free(b->items);
	free(b);
}

int main(void)
{
	int capacity = 5;
  buffer *b = initializeBuffer(capacity);
	enqueue(b, 1);
	enqueue(b, 2);
	enqueue(b, 3);
	enqueue(b, 4);
	/*enqueue(b, 5);*/
	out(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	out(b);
	freeBuffer(b);

	return 0;

}
