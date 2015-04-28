#include <stdio.h>

int main(void)
{
  unsigned int num, div;
	int isprime;

	printf("Enter an integer(q to quit): ");
	while(scanf("%u", &num))
	{
	  isprime=1;
		for(div=2; div*div<=num; ++div)
		{
			if(num%div==0)
			{
			  if(num!=div*div){ printf("%u, %u, ", div, num/div); }
				else{ printf("%u, ", div); }
				isprime=0;
			}
		}
		if(isprime){ printf("%u is a prime number.\n", num); }
		else{ printf("\b\b are divisors of %u.\n", num); }
		printf("\nEnter another integer(q to quit): ");
	}

  return 0;
}
