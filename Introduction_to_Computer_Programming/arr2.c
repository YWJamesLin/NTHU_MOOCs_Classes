#include <stdio.h>
#define MAXBIN 25
#define STARS "********************************"

int main(void)
{
	int hist[MAXBIN];
	int i, nbin;

	for(nbin=0; nbin<MAXBIN; ++nbin){ if(scanf("%d", hist+nbin)==EOF){ break; } }
	for(i=0; i<nbin; ++i)
	{
		printf("[%d]: %d ", i, hist[i]);
		printf("%.*s\n", hist[i], STARS);
	}

	return 0;
}
