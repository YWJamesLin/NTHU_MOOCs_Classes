#include <stdio.h>

void show(int (*p)[3])
{
	int i,j;
	
	for(i=0; i<2; ++i)
	{
		for(j=0; j<3; ++j){ printf("%d ", p[i][j]); }
		printf("\n");
	}
	for(i=0; i<2; ++i)
	{
		for(j=0; j<3; ++j){ printf("%d ",*(&p[0][0]+3*i+j)); }
		printf("\n");
	}
}

int main(void)
{
	int a[][3] = {1, 2, 3, 4, 5, 6};
	
	show(a);

	return 0;
}
