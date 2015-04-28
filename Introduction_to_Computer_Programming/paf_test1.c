#include <stdio.h>

void sort(int *bp, int *ep)
{
	int *minp = bp;
	int *p = bp;
	int t;

	if(bp==ep){ return; }
	for(++p; p<=ep; ++p)
	{
		if(*minp > *p){ minp = p; }
	}
	t = *bp;
	*bp = *minp;
	*minp = t;
	sort(bp+1, ep);
}

int main(void)
{
	int a[] = {6, 5, 7, 3, 2, 0, 1};
	int i = 0;

	sort(a, a+6);
	for(i=0; i<7; ++i){ printf("%d", a[i]); }
	
	return 0;
}
