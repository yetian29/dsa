#include <stdio.h>
#include <string.h>


int main(void)
{
	/*int array[] = {1, 2, 3, 4, 5};*/
	/*int sizeArray = sizeof(array) / sizeof(array[0]);*/
	/*printf("Size Array: %d\n", sizeArray);*/
	/*for (int i = 0; i < sizeArray; i++)*/
	/*{*/
	/*	printf("Value: %d\n", array[i]);*/
	/*	printf("Pointer Address: %p\n", array + i);*/
	/*}*/

	char name[] = "DaThien";
	int sizeName = sizeof(name) / sizeof(name[0]);
	int lengthName = strlen(name);	
	printf("Size Name: %d\n", sizeName);
	printf("Length Name: %d\n", lengthName);
	for (int i = 0; i < lengthName; i++)
	{
		printf("%c\n", name[i]);
		printf("%p\n", name + i);
	}
	return 0;
}
