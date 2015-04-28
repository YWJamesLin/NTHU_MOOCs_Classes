#include <stdio.h>

int main(void)
{
  int x;
  int y;

  printf("Enter two integers: ");
  scanf("%d%d", &x, &y);
  printf("%d\n", x+y);
  return 0;
}
