#include <stdio.h>

int main(void)
{
	int i=0, j;
  char str[100];

	scanf("%s%n", str, &j);
	--j;
	while(i<j)
	{
	  if(str[i] != str[j]){ break; }
		i++;
		j--;
	}
	if(i<j){ printf("Not a palindrome.\n"); }
	else{ printf("A palindrome.\n"); }

	return 0;
}
