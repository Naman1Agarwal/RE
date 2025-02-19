#include <stdio.h>

int main()
{
	int a, b, c;
	a = 0x1a;
	b = 0xfe;
	c = 0x123;

	c = a*b-c;

	printf("%x\n", c);
	return 0;
}
