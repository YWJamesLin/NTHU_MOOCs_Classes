#include <stdio.h>

void i2b(int);

int main(void)
{
	int x;
	scanf("%d", &x);
	i2b(x);
}

void i2b(int n)
{
  if(n==0) return;
  i2b(n/2);
	printf("%d", n%2);
}
