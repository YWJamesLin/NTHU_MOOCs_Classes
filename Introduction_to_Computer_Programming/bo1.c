#include <stdio.h>

unsigned getBits(unsigned, int, int);
unsigned invert(unsigned, int, int);
unsigned rightRotate(unsigned, int);
void dispBits(unsigned);

int main(void)
{
	unsigned n;
	n=0xab00;
	dispBits(n);
	dispBits(n&0x1f);
	dispBits(n|0x1f);
	dispBits(n^0x1f);
	dispBits(~n);
	dispBits(getBits(n, 16, 8));
	dispBits(invert(n, 16, 8));
	dispBits(rightRotate(n, 12));

	return 0;
}

void dispBits(unsigned val)
{
	int i;
	unsigned mask=1<<31;
	
	for(i=0; i<32; ++i)
	{
		printf("%d", !!(mask&val));
		mask>>=1;
	}
	puts("");
}

unsigned int getBits(unsigned x, int p, int n)
{
	return (x>>(p-n))&~(~0<<n);
}

unsigned invert(unsigned x, int p, int n)
{
	return  (x ^ (~((~0)<<n)<<(p-n)))>>(p-n);
}

unsigned rightRotate(unsigned x, int n)
{
	return ((x&~(~0<<n))<<(32-n))|(x>>n);
}
