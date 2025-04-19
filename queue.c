#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
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


void enqueue(queue *q, int x)
{
	if ( (q->tail + 1) % size == q->head )
	{
		 fprintf(stderr, "Overflow\n");
		 exit(1);
	}
	q->items[q->tail] = x;
	q->tail = (q->tail + 1) % size;
	count++;
}

void dequeue(queue *q)
{
	if (q->head == q->tail)
	{
		 fprintf(stderr, "Underflow\n");
		 exit(1);
	}
	q->head = (q->head + 1) % size;
	count--;
}

void out(queue *q)
{
	int i = 0;
	int start = q->head;
	printf("Head: %d, Tail: %d, Count: %d\n", q->head, q->tail, count);
	while (i < count)
	{
		printf("%d", q->items[start]);
		if (i < count - 1) printf(" | ");
		i++;
		start = (start + 1) % size;
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
	enqueue(&q, 5);
	enqueue(&q, 6);
	dequeue(&q);
	out(&q);

}
