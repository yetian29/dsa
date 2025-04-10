#include <stdio.h>

int main(void)
{
	int array[] = {1, 2, 3, 4, 5, 6};
	int sizeArray = sizeof(array) / sizeof(array[0]);
	printf("Size of array: %d\n", sizeArray);
	for (int i = 0; i < sizeArray; i++)
	{
		printf("%p\n", (char *)array + (sizeof(int) * i));
	}

	return 0;
}
