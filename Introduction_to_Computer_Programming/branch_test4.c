#include <stdio.h>

int main(void)
{
	int in;
	scanf("%d", &in);
	switch(in)
	{
		case 0:
			printf("Monday");
			break;
		case 1:
			printf("Tuesday");
			break;
		case 2:
			printf("Wednesday");
			break;
		case 3:
			printf("Thursday");
			break;
		case 4:
			printf("Friday");
			break;
    case 5:
			printf("Saturday");
			break;
		case 6:
			printf("Sunday");
			break;
	}
  return 0;
}
