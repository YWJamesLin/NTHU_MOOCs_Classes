#include <stdio.h>

int main(void)
{
	int a[50], i, j, *ptr[10];

	for(i=0; i<50; ++i){ a[i] = i; }
	for(i=0; i<10; ++i){ ptr[i] = a+5*i; }
	for(i=0; i<10; ++i)
	{
		printf("ptr[%d]=%p:\t", i, ptr[i]);
		for(j=0; j<5; ++j){ printf("%3d", *(*(ptr+i)+j)); }
		printf("\n");
	}

	return 0;
}
