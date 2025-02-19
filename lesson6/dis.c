#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;
	a = 0x16;
	b = 0x6;
	c = 0x39;

	c = a*b-c;

	printf("%d\n", c);
	
	return 0;
}
