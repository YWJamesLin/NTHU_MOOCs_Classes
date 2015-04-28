#include <stdio.h>
#define SIZE 4

int main(void)
{
	int idata[SIZE] = {1, 2, 3, 4}, *pti=idata, k;
	char cdata[SIZE] = {'A', 'B', 'C', 'D'}, *ptc=cdata;

	for(k=0; k<SIZE; ++k){ printf("%p %c\t%p %d\n", ptc+k, *(ptc+k), pti+k, *(pti+k)); }
	
	return 0;
}
