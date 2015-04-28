#include <stdio.h>

int fact(int);
int fac_r(int, int);

int main(void)
{
	int n;
	
	scanf("%d", &n);
	printf("%d! = %d\n", n, fact(n));
 	printf("%d! = %d\n", n, fact_r(n, 1));

	return 0;
}

int fact(int in)
{
  int ans = 1;

	while(in>0)
	{
		ans = ans*in;
		--in;
	}
	return ans;
}

int fact_r(int in, int ans)
{
	if(in!=1){ return fact_r(in-1, in*ans); }
	else{ return ans; }
}
