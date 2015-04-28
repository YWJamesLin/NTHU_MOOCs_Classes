#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum{MAX_LEN=256};

int main(void)
{
	char **p, **q;
	char buf[MAX_LEN+1];
	int maxline=1, i, j;

	p=(char **)malloc(maxline*sizeof(*p));
	i=0;
	while(fgets(buf, MAX_LEN+1, stdin))
	{
		if(i>=maxline)
		{
			maxline*=2;
			q=(char **)realloc(p, maxline*sizeof(*p));
			if(!q)
			{
				for(j=0; j<i; ++j){ free(p[j]); }
				free(p);
				return EXIT_FAILURE;
			}
			p=q;
		}
		p[i]=(char *)malloc(strlen(buf)+1);
		if(!p[i])
		{
			for(j=0; j<i; ++j){ free(p[j]); }
			free(p);
			return EXIT_FAILURE;
		}
		strcpy(p[i], buf);
		++i;
	}
	for(j=0; j<i; ++j)
	{
		printf("%s", p[j]);
		free(p[j]);
	}
	free(p);

	return 0;
}
