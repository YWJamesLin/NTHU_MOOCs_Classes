#include <stdio.h>

int pow2(int);
void show_binary(int, int);

int main(void)
{
  int in, limit, i;

	printf("Please enter the number of bits: ");
	scanf("%d", &in);
	limit = pow2(in);
	printf("%d\n", limit);
	for(i=0; i<limit; ++i)
	{ 
		show_binary(i, limit); 
		printf(":\t%2d\n", i);
	}
  return 0;
}

int pow2(int n)
{
  int ans = 1;
	
	while(n)
	{
	  ans *= 2;
		n--;
	}

	return ans;
}
void show_binary(int x, int limit)
{
	limit/=2;
	while(limit>0)
	{
	  printf("%d", x/limit);
		x%=limit;
		limit/=2;
	}
}
