#include <stdio.h>

typedef struct t_node
{
	int data;
	struct t_node *nextptr;
}t_node;

int main(void)
{
	t_node n1, n2;

	n1.nextptr=&n2;
	n2.nextptr=&n1;
	n1.nextptr->data=20;
	n2.nextptr->data=10;
	printf("n1.data: %d, n2.data: %d\n", n1.data, n2.data);
	
	return 0;
}
