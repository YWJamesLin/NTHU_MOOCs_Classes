#include <stdio.h>

int sum(int *, int *);


int main(void)
{
	int a[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
	int total;

	total=sum(a, a+9);
	printf("total: %d\n", total);

	return 0;
}

int sum(int *beginp, int *endp)
{
	int ans=0;
	
	printf("endp: %p\n", endp);
	printf("beginp: ");
	while(beginp <= endp)
	{
		printf("%p ", beginp);
		ans += *beginp;
		beginp++;
	}
	printf("\n");

	return ans;
}
