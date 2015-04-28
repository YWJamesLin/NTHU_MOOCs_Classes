#include <stdio.h>
int bsearch(int *, int, int, int);
int main(void)
{
	int a[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55}, key, index;

	scanf("%d", &key);
	index = bsearch(a, 0, sizeof(a)/sizeof(int)-1, key);
	if(index < 0){ printf("Not found.\n"); }
	else{ printf("[%d]: %d\n", index , a[index]); }

	return 0;
}

int bsearch(int *a, int left, int right, int key)
{
	int mid = (left+right)/2;
	if(left > right){ return -1; }

	if(key == a[mid]){ return mid; }
	else if(key < a[mid]){ return bsearch(a, left, mid, key); }
	else{ return bsearch(a, mid+1, right, key); }
	
}
