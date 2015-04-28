#include <stdio.h>

int main(void)
{
	int y, *ptr;
	
	scanf("%d", &y);
	ptr = &y;
	printf("%p -> %d", ptr, *ptr);

	return 0;
}
