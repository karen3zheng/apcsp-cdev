#include <stdio.h>

int main()
{
	int a = 545;
	char b = 'b';
	float c = 1.23;
	double d = 2.34;
	unsigned int e = 10;
	long int f = 1;

	printf("int a value: %d, and size: %lu bytes\n", a, sizeof(a));
	printf("char b value: %c, and size: %lu bytes\n", b, sizeof(b));
	printf("float c value: %f, and size: %lu bytes\n", c, sizeof(c));
	printf("double d value: %lf, and size: %lu bytes\n", d, sizeof(d));
	printf("unsigned int e value: %lu, and size: %lu bytes\n", e, sizeof(e));
	printf("long int f value: %li, and size: %lu bytes\n", f, sizeof(f));
}
