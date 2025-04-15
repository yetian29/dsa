#include <stdio.h>
#include <stdlib.h>

// One dimensional array
/*int main(void)*/
/*{*/
/*	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};*/
/*	int size = sizeof(array) / sizeof(array[0]);*/
/*	printf("Size: %d\n", size);*/
/*	for (int i = 0; i < size; i++)*/
/*	{*/
/*		printf("%d\n", array[i]);*/
/*		printf("%p\n", (char *)array + sizeof(int) * i);*/
/*	}*/
/*	return 0;*/
/*}*/

// Two dimensional array


/*int main(void)*/
/*{*/
/*	int array[2][3] = {1, 2, 3, 4, 5, 6};*/
/*	int size = sizeof(array) / sizeof(array[0][0]);*/
/*	for (int i = 0; i < 2; i++)*/
/*	{*/
/*		for (int j = 0; j < 3; j++)*/
/*		{*/
/*			printf("%d\n", array[i][j]);*/
/*			printf("%p\n", (char *)array + sizeof(int) * (i * 3 + j));*/
/*		}*/
/*	}*/
/*	printf("Size: %d\n", size);*/
/**/
/*	return 0;*/
/*}*/


// Dynamic array

typedef struct 
{
	int size; // Size of elements have occupied in dynamic array
	int capacity; // Capacity of dynamic array
	int *items; // Dynamic array stored elements
} bucket;

bucket *initializeBucket(int capacity)
{

	bucket *bk = malloc(sizeof(bucket));
	if (!bk)
	{
		fprintf(stderr, "Allocation memory for bucket failed\n");
		exit(1);
	}
	bk->items = malloc(capacity * sizeof(int));
	if (!(bk->items))
	{
		fprintf(stderr, "Allocation memory for bucket items failed\n");
		exit(1);
	}
	bk->size = 0;
	bk->capacity = capacity;
	return bk;
}

bool isEmpty(bucket *bk)
{
	if (bk->size == 0) return true;
	return false;
}

void append(bucket *bk, int data)
{
	// Bucket is empty
	if (isEmpty(bk))
	{
		bk->items[bk->size] = data;
		bk->size++;
		return;
	}
	// Bucket is full
	if (bk->size == bk->capacity)
	{
		bk->capacity *= 2;
		bk->items = realloc(bk->items, sizeof(int) * (bk->capacity));
	}
	bk->items[bk->size] = data;
	bk->size++;
}

void insert(bucket *bk, int data, int position)
{
	// Bucket is empty
	if (isEmpty(bk) && position == 0)
	{
		bk->items[position] = data;
		bk->size++;
		return;
	}
	// Bucket is full
	if (bk->size == bk->capacity)
	{
		bk->capacity *= 2;
		bk->items = realloc(bk->items, sizeof(int) * (bk->capacity));
	}
	// Bucket has occupied elements
	for (int i = bk->size - 1; i >= position; i--)
	{
		bk->items[i + 1] = bk->items[i];
	}
	bk->items[position] = data;
	bk->size++;
}

void delete(bucket *bk, int position)
{
	// Bucket is empty
	if (isEmpty(bk))
	{
		fprintf(stderr, "Bucket is empty\n");
		exit(1);
	}

	for (int i = position + 1; i < bk->size; i++)
	{
		bk->items[i - 1] = bk->items[i];
	}
	bk->size--;
}

void pop(bucket *bk)
{
	if (isEmpty(bk))
	{
		fprintf(stderr, "Bucket is empty\n");
		exit(1) ;
	}
	bk->size--;

}

void out(bucket *bk)
{
	if (isEmpty(bk))
	{
		printf("Bucket is empty\n");
		return;
	}
	printf("Size: %d, Capacity: %d\n", bk->size, bk->capacity);
			
	for (int i = 0; i < bk->size; i++)
	{
		printf("%d", bk->items[i]);
		if (i < bk->size - 1) printf(" | ");
	}
	printf("\n");

}



int main(void)
{
	int capacity = 1;
	bucket *bk = initializeBucket(capacity);
	append(bk, 1);
	append(bk, 2);
	append(bk, 3);
	append(bk, 4);
	out(bk);
	/*pop(bk);*/
	insert(bk, 5, 0);
	insert(bk, 6, 2);
	out(bk);
	delete(bk, 0);
	out(bk);

	return 0;
}
