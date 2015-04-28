#include <stdio.h>

int main(void)
{
  int x;

  x = 5;
  printf("x = %d\n", ++x);
  printf("x = %d\n", ++x);
  printf("x = %d\n", x);

  return 0;
}
