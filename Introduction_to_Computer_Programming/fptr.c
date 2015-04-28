#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void strUpper(char *sp)
{
	while(*sp!='\0')
	{
		printf("%c", toupper(*sp));
		sp++;
	}
}

void strLower(char *sp)
{
	while(*sp!='\0')
	{
		printf("%c", tolower(*sp));
		sp++;
	}
}

void show(void (*pf)(char *), char *str)
{
	(*pf)(str);
	puts("");
}

int main(void)
{
	char str[100];
	void (*pf)(char *);

	fgets(str, 100, stdin);
	str[strlen(str)-1]='\0';
	pf=strUpper;
	show(pf, str);
	pf=strLower;
	show(pf, str);

	return 0;
}
