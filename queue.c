#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define capacity 5


int count = 0;

typedef struct
{
	int head;
	int tail;
	int items[capacity];
} queue;


void initialize(queue *q)
{
	q->head = 0;
	q->tail = 0;
}


bool isFull(queue *q)
{
	/*if (q->head == q->tail + 1  || q->head == 0 && q->tail == capacity - 1) return true;*/
	return count == capacity - 1;
}

bool isEmpty(queue *q)
{
	/*return q->head == q->tail;*/
	return count == 0;
}


void enqueue(queue*q, int x)
{
	if (isFull(q))
	{
		fprintf(stderr, "Overflow\n");
		exit(1);
	}
	q->items[q->tail] = x;
	q->tail = (q->tail + 1) % capacity;
	count++;
}

void dequeue(queue*q)
{
  if (isEmpty(q))
	{
		fprintf(stderr, "Underflow\n");
		exit(1);
	}
	q->head = (q->head + 1) % capacity;
	count--;
}


void out(queue *q)
{
	printf("Head: %d, Tail: %d, Count: %d\n", q->head, q->tail, count);
	int i = q->head;
	for (int j = 0; j < count; j++)
	{
		printf("%d", q->items[i]);
		if (j < count - 1) printf(" | ");
		i = (i + 1) % capacity;
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
	dequeue(&q);
	enqueue(&q, 5);
	dequeue(&q);
	enqueue(&q, 6);
	out(&q);
	/*dequeue(&q);*/
	/*dequeue(&q);*/
	/*dequeue(&q);*/
	/*dequeue(&q);*/
	/*dequeue(&q);*/
	/*out(&q);*/
	return 0;
}
