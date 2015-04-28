#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{NUM_WORDS=20, MAX_LEN=30};

int scmp(const void *p1, const void *p2)
{
	char *v1, *v2;
	v1=*(char **)p1;
	v2=*(char **)p2;
	return strcmp(v1, v2);
}

int main(void)
{
	char buf[MAX_LEN+1];
	char *words[NUM_WORDS];
	int i=0, j;

	while(i<NUM_WORDS && fgets(buf, MAX_LEN+1, stdin)!=NULL)
	{
		buf[strlen(buf)-1]='\0';
		words[i]=(char *)malloc(strlen(buf)+1);
		strcpy(words[i], buf);
		++i;
	}
	qsort(words, i, sizeof(*words), scmp);
	for(j=0; j<i; ++j)
	{ 
		printf("%s\n", words[j]);
		free(words[j]);
	}

	return 0;
}
