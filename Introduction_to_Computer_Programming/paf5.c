#include <stdio.h>

void show_int_array(int *,int);
void swow_int_2d_array(int *[2], int);

int main(void)
{
	int z[4][2] = {{1,2}, {3,4}, {5,6}, {7,8}}, j;
	
	for(j=0; j<4; ++j){ show_int_array(z[j], 2); }
	printf("\n");
	show_int_2d_array(z, 4);

	return 0;
}

void show_int_array(int *a, int n)
{
	int i;
	
	for(i=0; i<n; ++i){ printf("%d ", *(a+i)); }
	printf("\n");
}

void show_int_2d_array(int (*a)[2], int k)
{
	int i,j;
	for(i=0; i<k; ++i)
	{
		for(j=0; j<2; ++j)
		{ printf("%d ", a[i][j]); }
		printf("\n");
	}
}
