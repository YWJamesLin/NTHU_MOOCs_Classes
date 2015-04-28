#include <stdio.h>

void permute(char *, int);
void swap(char *, char *);

int main(void)
{
	char a[]  = "abcd";

	permute(a, 4);

	return 0;
}

void permute(char *a, int len)
{
	int i;

	if(len == 1){ printf("%s\n", a); }
	else
	{
		for(i=len-1; i>=0; --i)
		{
			swap(a+i, a+len-1);
			permute(a, len-1);
			swap(a+i, a+len-1);
		}
	}
}

void swap(char *x, char *y)
{
	char tmp;
	tmp = *x;
	*x = *y;
	*y = tmp;
}
