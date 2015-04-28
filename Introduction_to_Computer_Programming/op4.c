#include <stdio.h>

int main(void)
{
  unsigned int a;
  int b;

  a = 10;
  b = -3;
  printf("%d\n", 1.*a < b);

  return 0;
}
