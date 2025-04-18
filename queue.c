#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 5

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
	return q->tail == size - 1 ;
}

bool isEmpty(queue *q)
{
   return q->head == q->tail;	
}

int enqueue(queue *q, int x)
{
	if (isFull(q))
	{
		fprintf(stderr, "Overflow\n");
		q->tail = 0;
		return 1;
	}	
	q->items[q->tail] = x;
	q->tail++;
	return 0;
}

int dequeue(queue *q)
{
	if (isEmpty(q))
	{
		fprintf(stderr, "Underflow\n");
		q->head = 0;
		q->tail = 0;
		return 1;
	}
	q->head++;
	return 0;
}

void out(queue*q)
{
	printf("Head: %d, Tail: %d\n", q->head, q->tail);
	for (int i = q->head; i < q->tail;i++)
	{
		printf("%d", q->items[i]);
		if (i < q->tail - 1) printf(" | ");
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
	/*enqueue(&q, 5);*/
	out(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	dequeue(&q);
	/*dequeue(&q);*/
	out(&q);
	return 0;
}
