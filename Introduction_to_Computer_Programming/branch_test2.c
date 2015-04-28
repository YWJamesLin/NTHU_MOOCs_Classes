#include <stdio.h>

int main(void)
{
  int i,j;
	unsigned char isprime;

  printf("2, ");
	for(i=3; i<=100; i+=2)
	{
	  isprime=1;
		for(j=3; j*j<=i; j+=2)
		{
		  if(i%j==0)
			{ 
				isprime=0;
				break;
			}
		}
		if(isprime){ printf("%d, ", i); }
	}
	printf("\b\b \b");
	
	return 0;
}
