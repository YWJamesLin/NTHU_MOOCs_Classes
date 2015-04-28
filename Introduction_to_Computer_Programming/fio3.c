#include <stdio.h>

int main(void)
{
  char word[46];
  int len;

  scanf("%45s%n", word, &len);
  printf("~%*.*s~\n", len*2, len/2, word);

  return 0;
}
