#include <stdio.h>

int main(void)
{
  printf("int: %u bytes, char: %u bytes.\n", sizeof(int), sizeof(char));
  printf("float: %u bytes, double: %u bytes.\n", sizeof(float), sizeof(double));

  return 0;
}
