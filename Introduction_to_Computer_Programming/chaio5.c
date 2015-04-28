#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int x=0;
	char ch;
	
	while((ch=getchar())!='\n')
	{
	  if(!isdigit(ch)){ break; }
		x = x * 10 + ch - '0';
	}
	printf("x = %d", x);

	return 0;
}
