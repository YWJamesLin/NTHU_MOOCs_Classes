#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *a, **b, rows, cols, i, j;

	scanf("%d%d", &rows, &cols);
	a=(int *)malloc(rows*cols*sizeof(int));
	for(i=0; i<rows*cols; ++i){ a[i]=i; }
	b=(int **)malloc(rows*sizeof(int *));
	for(i=0; i<rows; ++i){ b[i]=a+i*cols; }
	for(i=0; i<rows; ++i)
	{
		for(j=0; j<cols; ++j){ printf("%3d", b[i][j]); }
		puts("");
	}
	free(b);

	return 0;
}
