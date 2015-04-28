#include <stdio.h>

int main(void)
{
  int i, j;
  int ch;

	printf("please  enter an uppercase letter:");
	ch = getchar();
	for(i='A'; i<=ch; ++i)
	{
	  for(j=i; j<=ch-1; ++j){ putchar(' '); }
	  for(j='A'; j<=i; ++j){ putchar(j); }
		for(j=i-1; j>='A'; j--){ putchar(j); }
		printf("\n");
	}

	return 0;
}
