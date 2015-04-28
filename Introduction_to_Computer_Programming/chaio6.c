#include <stdio.h>

int main(void)
{
  int i=0, x=0;
	char str[100];

	scanf("%s", str);
	while(str[i]!='\0')
	{
		if(!isdigit(str[i])){ break; }
		x = x * 10 + str[i] - '0';
		i++;
	}
	printf("x = %d", x);

  return 0;
}
