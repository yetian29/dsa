#include <stdio.h>

// One dimentional array
/*int main(void)*/
/*{*/
/*	int array[] = {1, 2, 3, 4, 5, 6};*/
/*	int sizeArray = sizeof(array) / sizeof(array[0]);*/
/*	printf("Size of array: %d\n", sizeArray);*/
/*	for (int i = 0; i < sizeArray; i++)*/
/*	{*/
/*		printf("%p\n", (char *)array + (sizeof(int) * i));*/
/*	}*/
/**/
/*}*/
/**/

// Two dimentional array
int main(void)
{
	int array[2][3] = {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%d\n", array[i][j]);
			printf("%p\n", (char *) array + (sizeof(int) * i) + (sizeof(int) * j));
		}
	}
	return 0;
}

