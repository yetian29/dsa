#include <stdio.h>

int main(void)
{
	int arrayInteger[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int sizeArrayInteger = sizeof(arrayInteger) / sizeof(arrayInteger[0]);
	for (int i = 0; i < sizeArrayInteger; i++)
	{
		printf("%d\n", arrayInteger[i]);
		printf("%p\n", arrayInteger + i);
	}
	
	return 0;
}
