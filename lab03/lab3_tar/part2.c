#include <stdio.h>

int main()
{
	int a, b, c;
	a = 0xe;
	c = 0x0;
	b = 0x1;
	
	while (b <= a){
		c += b;
		b++;
	}

	printf("%d\n", c);
	return 0;
}
