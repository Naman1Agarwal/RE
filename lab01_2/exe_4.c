
#define FLAWED
#define HUMAN
#define WEAK	2025
#undef FLAWED

int main()
{
	char secret[20] = {10};
	int i;

	for (i = 0; i < sizeof secret; i++)
	{
		secret[i] += i;
		secret[i] |= 0x40;
	}
	secret[3] = 'K';
	#ifdef HUMAN
		secret[i-10] = 'r';
		secret[i-18] = 0143;
		secret[i-15] = 104;
	#endif
	secret[12] = 0170;
	#ifdef FLAWED
		secret[i-2] = '3';
		secret[i-9] = 0x55;
		secret[i-13] = 85;
	#endif
	secret[11] = '0' + 1;
	secret[13] = secret[13] ^ secret[13];
	#ifdef WEAK
		secret[i-16] = 't';
		secret[i-19] = 0x40;
		secret[i-14] = 51;
	#endif
	secret[0] ^= 34;
	i = i /2 -1;
	secret[i--] = 0x54;
	secret[--i] = 109;
	secret[++i] += 25;
	#ifndef DESTROY
	for(i=0; i< sizeof secret; i++)
		secret[i] -= secret[i];
	#endif
}
