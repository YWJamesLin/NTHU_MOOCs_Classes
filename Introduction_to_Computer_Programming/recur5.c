#include <stdio.h>

int gcd(int, int);

int main(void)
{
  int x, y;
	
	scanf("%d%d", &x, &y);
	printf("%d\n", gcd(x,y));

  return 0;
}

int gcd(int x, int y)
{
	if(y==0){ return x; }
	else if(y==1){ return 1; }
  if(x < y)
	{
	  x += y;
		y = x - y;
		x -= y;
	}
	if(x%2==0)
	{
	  if(y%2==0){ return 2 * gcd(x/2, y/2); }
		else{ return gcd(x/2,y); }
	}
	else
	{ 
		if(y%2==0){ return gcd(x,y/2); }
		else{ return gcd((x-y)/2, y); }
	}
}
