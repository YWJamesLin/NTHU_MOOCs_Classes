#include <stdio.h>

int main(void)
{
  int i,j,isprime;

  printf("1, ");
	for(i=3; i<=100; ++i)
	{
	  isprime=1;
	  for(j=2;j*j<=i; ++j)
		{
		  if(i%j==0)
			{
			  isprime=0;
				break;
			}
		}
		if(!isprime){ printf("%d, ", i); }
	}
	printf("\b\b");
	
	return 0;
}
