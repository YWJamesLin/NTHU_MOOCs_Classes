#include <stdio.h>

int main(void)
{
	int i=0, sum=0;
  char binary[20];
	
	scanf("%s", binary);
	while(binary[i]!='\0')
	{
		sum = sum * 2 + binary[i]-48;
		++i;
	}
	printf("%d\n", sum);

  return 0;
}
