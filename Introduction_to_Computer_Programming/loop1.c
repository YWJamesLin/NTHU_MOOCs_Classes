#include <stdio.h>

int main(void)
{
  int n = 1;

  while(n<3)
  {
    printf("n - %d\n", n);
    n++;
    printf("new n = %d\n", n);
  }
  printf("The loop is done.\n");

  return 0;
}
