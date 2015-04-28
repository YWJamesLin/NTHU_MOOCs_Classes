#include <stdio.h>

int islower(char);
char tolower(char);

int main(void)
{
  char in;
	
	while(scanf("%c", &in))
	{
	  if(islower(in)){ printf("lower case\n"); }
		else{ printf("%c\n", tolower(in)); }
		getchar();
	}

	return 0;
}

int islower(char in)
{
  if(in>96 && in<123){ return 1; }
	else{ return 0; }
}

char tolower(char in)
{
  return in+32;
}
