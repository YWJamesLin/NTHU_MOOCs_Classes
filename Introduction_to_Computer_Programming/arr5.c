#include <stdio.h>

int main(void)
{
	int a[][4] = {{1,2,3,4},{5,6},{9,10,11,12} };
	int b[][4]={1,2,3,4,5,6,9,10,11,12};
	int i,j;
	
	printf("a:        %d bytes\n", sizeof(a));
	printf("a[0]:     %d bytes\n", sizeof(a[0]));
	printf("a[0][0]:  %d bytes\n\n", sizeof(a[0][0]));
	for(i=0; i<3; ++i)
	{
		for(j=0; j<4; ++j){ printf("%3d", a[i][j]); }
		printf("\n");
	}
	printf("\n");
	printf("b:        %d bytes\n", sizeof(b));
	printf("b[0]:     %d bytes\n", sizeof(b[0]));
	printf("b[0][0]:  %d bytes\n\n", sizeof(b[0][0]));
	for(i=0; i<3; ++i)
	{
		for(j=0; j<4; ++j){ printf("%3d", b[i][j]); }
		printf("\n");
	}

	return 0;
}
