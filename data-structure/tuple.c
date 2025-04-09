#include <stdio.h>
#include "tuple.h"

struct Tuple
{
	const int a;
	const int b;
	const int c;
};


Tuple initialize(int a, int b, int c)
{
	Tuple t = {a, b, c};
	return t;
}

bool comparation(Tuple t1, Tuple t2)
{
	if (t1.a == t2.a && t1.b == t2.b && t1.c == t2.c) return true;
	return false;

}


int main(void)
{
	int a = 1, b = 2, c = 3;
	Tuple t1 = initialize(a, b, c);
	Tuple t2 = initialize(c, b, a);
	Tuple t3 = initialize(a, b, c);
	printf("%d, %d, %d\n", t1.a, t1.b, t1.c);
	/*t1.a = 4;*/
	/*printf("%d\n", t.a);*/
	printf("%s\n", comparation(t1, t2) ? "True": "False");
	printf("%s\n", comparation(t1, t3) ? "True": "False");

}
