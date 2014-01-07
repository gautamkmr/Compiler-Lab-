#include <stdio.h>

int foo()
{
	printf("foo()");
	return 0;
}
void foo(int a)
{
	printf("foo(int) %d", a);
}

int main()
{
	foo();
	foo(12);
	return 0;
}
