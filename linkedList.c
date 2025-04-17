#include <stdio.h>
#include <stdlib.h>


// Node for Doubly Linked List
typedef struct node
{
	struct node *prev;
	int key;
	struct node *next;
} node;

typedef struct 
{
	node *head;
	node *tail;
} dll;

void initializeDLL(dll *list)
{
	list->head = NULL; 
	list->tail = NULL;
}

node *createNewNode(dll *list, int value)
{
	node *new_node = malloc(sizeof(node));
	if (!new_node)
	{
		fprintf(stderr, "Allocation memory for new node failed\n");
		exit(1);
	}
	new_node->prev = NULL;
	new_node->key = value;
	new_node->next = list->head;
	return new_node;
}

void prepend(dll *list, int value)
{
  node *new_node = createNewNode(list, value);
	if (list->head != NULL)
	{
		(list->head)->prev = new_node;
	}
	list->head = new_node;

}

void out(dll *list)
{
	node *ptr = list->head;
	if (ptr == NULL)
	{
		printf("Doubly linked list is empty\n");
		return;
	}
	while (ptr)
	{
		printf("%d", ptr->key);
		ptr = ptr->next;
		if (ptr != NULL) printf(" -> ");

	}
	printf("\n");
}
	 

int main(void)
{
	dll list;
	/*prepend(&list, 1);*/
	/*prepend(&list, 2);*/
	/*prepend(&list, 3);*/
	/*prepend(&list, 4);*/
	/*prepend(&list, 5);*/
	out(&list);

	return 0;
}
