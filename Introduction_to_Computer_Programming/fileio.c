#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LINE_LEN 40
#define NUM_WORDS 5000

char dictionary[NUM_WORDS][LINE_LEN];

int main(void)
{
	FILE *fp;
	int nw, i;

	if(!(fp=fopen("5000_words", "r")))
	{
		puts("Cannot open file.");
		exit(1);
	}
	nw=0;
	while(!feof(fp) && nw<NUM_WORDS)
	{
		fscanf(fp, "%s", dictionary[nw]);
		while(!feof(fp) && fgetc(fp)!='\n');
		++nw;
	}
	fclose(fp);
	srand((unsigned)time(NULL));
	for(i=0; i<10; ++i)
	{
		printf("%s\n", dictionary[(int)(5000.*rand()/(1.+RAND_MAX))]);
	}

	return 0;
}
