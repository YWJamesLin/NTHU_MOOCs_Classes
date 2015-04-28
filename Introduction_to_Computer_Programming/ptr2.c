#include <stdio.h>

void swap(int *, int *);

int main(void)
{
	int x, y;

	scanf("%d%d", &x, &y);
	printf("x: %d, y: %d\n", x, y);
	swap(&x, &y);
  printf("x: %d, y: %d\n", x, y);

	return 0;
}

void swap(int *a, int *b)
{
  *a += *b;
	*b = *a-*b;
	*a -= *b;
}
