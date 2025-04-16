#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int capacity;
	int start;
	int end;
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
	b->items = malloc(capacity * sizeof(int));
	if (! (b->items) )
	{
		fprintf(stderr, "Allocation memory for buffer items failed\n");
		exit(1);
	}
	b->capacity = capacity;
	b->start = 0;
	b->end = 0;
	return b;

}

void enqueue(buffer *b, int data)
{
	// Buffer is full
	if ( (b->end + 1) % (b->capacity + 1) == (b->start) )
	{
		fprintf(stderr, "Buffer is full\n");
		exit(1);
	}
	b->items[b->end] = data;
	b->end = (b->end + 1) % (b->capacity + 1);
}

void dequeue(buffer *b)
{
	// Buffer is empty
	if (b->start == b->end)
	{
		fprintf(stderr, "Buffer is empty\n");
		b->start = (b->start + 1) % (b->capacity + 1);
		exit(1);
	}
	b->start = (b->start + 1) % (b->capacity + 1);

}

void out(buffer *b)
{
	printf("Start: %d, End: %d, Capacity: %d\n", b->start, b->end, b->capacity);

	for (int i = b->start; i < b->end; i++)
	{
		printf("%d", b->items[i]);
		if (i < b->end - 1) printf(" | ");
	}

	printf("\n");

}

void freeQueue(buffer *b)
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
	enqueue(b, 5);
	/*enqueue(b, 6);*/
	out(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	dequeue(b);
	out(b);
	freeQueue(b);
	return 0;
}
