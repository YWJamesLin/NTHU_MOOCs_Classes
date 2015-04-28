#include <stdio.h>

int main(void)
{
  unsigned int j = 4294967295;
  int i = 2147483647;

  printf("%d %d %d\n", i, i+1, i+2);
  printf("%u %u %u\n", j, j+1, j+2);

  return 0;
}
