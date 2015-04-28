#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int ch;
	
	printf("Enter a letter or type # to quit: ");
	while( ( ch=getchar() ) != '#')
	{
	  if(ch=='\n'){ continue; }
		if(isalpha(ch))
		{
			switch(ch)
			{
		 		case 'A':
				case 'a':
					printf("Apple.\n");
					break;
				case 'B':
				case 'b':
					printf("Book.\n");
					break;
				case 'C':
				case 'c':
					printf("Cat.\n");
					break;
				default:
					printf("!?!?!\n");
			}
		}
		while(getchar()!='\n'){ continue; }
		printf("\nEnter another letter or a #: ");
	}
	return 0;
}
