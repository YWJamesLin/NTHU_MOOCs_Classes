#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{MAX_LEN=60, NUM_WORDS=12000000};

int cmpfun(const void *va, const void *vb)
{
	char *a, *b;
	a=*(char **)va;
	b=*(char **)vb;
	return strcmp(a, b);
}

int main(void)
{
	char **p, buf[MAX_LEN+1], **np, *key;
	int i, j;
	FILE *fin;

	fin=fopen("words", "r");
	p=(char **)malloc(NUM_WORDS*sizeof(char *));
	i=0;
	while(i<NUM_WORDS && fgets(buf, MAX_LEN+1, fin)!=NULL)
	{
		buf[strlen(buf)-1]='\0';
		p[i]=(char *)malloc(sizeof(strlen(buf)+1));
		if(p[i]!=NULL)
		{
			strcpy(p[i], buf);
			++i;
		}
	}
	fclose(fin);
	printf("number of words: %d\n", i);
	while(fgets(buf, MAX_LEN+1, stdin))
	{
		buf[strlen(buf)-1]='\0';
		key=buf;
		np=bsearch(&key, p, i, sizeof(*p), cmpfun);
		if(np!=NULL){ printf("%d: %s\n", np-p+1, *np); }
		else{ printf("Not found.\n"); }
	}
	for(j=0; j<i; ++j){ free(p[j]); }
	free(p);

	return 0;
}
