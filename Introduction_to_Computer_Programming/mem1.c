#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	int array_size, i;
	double *ptd;

	srand((unsigned)time(NULL));
	scanf("%d", &array_size);
	ptd=(double *)malloc(array_size*sizeof(double));
	if(ptd==NULL)
	{ 
		printf("Failed.\n"); 
		exit(EXIT_FAILURE);
	}
	for(i=0; i<array_size; ++i)
	{
		ptd[i]=1.*rand()/(1.+RAND_MAX);
		if(ptd[i]>0.5){ printf("%d: %f\n", i, ptd[i]); }
	}
	free(ptd);

	return 0;
}
