#include <stdio.h>
#include <stdbool.h>
#define size 5


int count = 0;

typedef struct
{
	int head;
	int tail;
	int items[size];
} queue;

void initialize(queue *q)
{
	q->head = 0;
	q->tail = 0;
}

bool isFull(queue *q)
{
	return q->tail == size - 1;
}

bool isEmpty(queue *q)
{
	return q->head == q->tail;
}



void enqueue(queue *q, int x)
{
	q->items[q->tail] = x;
	count++;
	if (isFull(q))
	{
		q->tail = 0;
	}
	else
	{
		q->tail++;
	}
}

void dequeue(queue *q)
{
	if (isEmpty(q))
	{
		q->head = 0;
	}
	else 
	{
		q->head++;
		count--;
	}
}

void out(queue *q)
{
	printf("Head: %d, Tail: %d\n", q->head, q->tail);
	int i = q->head;
	while (i < count)
	{
		printf("%d", q->items[i]);
		i++;
		if (i < count) printf(" | ");
		if (i == size - 1)
		{
			i = 0;
		}
	}
	printf("\n");
}

int main(void)
{
	queue q;
	initialize(&q);
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 4);
	enqueue(&q, 5);
	enqueue(&q, 6);
	out(&q);
	return 0;
}
