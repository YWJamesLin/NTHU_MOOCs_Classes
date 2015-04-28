#include <stdio.h>

int main(void)
{
  int x;
  int y;
  
  scanf("%d%d", &x, &y);
  printf("%d = %d * %d + %d\n", x, y, x/y, x%y);

  return 0;
}
