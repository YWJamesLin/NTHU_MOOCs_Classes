#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int data;
	struct t_node *nextNode;
}Node;
void node_insert(Node **, int);
void node_delete(Node **, int);
void display_list(Node *);

int main()
{
	int val, method;
	Node * head=NULL;
	
	while(1)
	{
		puts("Input [method(1 to add or 0 to del)] [number] to add or del something to the list:");
		scanf("%d %d", &method, &val);
		if(method==1){ node_insert(&head, val); }
		else if(!method){ node_delete(&head,val); }
		else{ puts("Error method."); }
		display_list(head);
	}
	
	return 0;
}

void node_insert(Node **np, int val)
{
	Node *newPtr, *prevPtr, *currPtr;
	
	newPtr=(Node *)malloc(sizeof(Node));
	if(newPtr== NULL)
	{
		printf("Out of Memory!!!!\n"); 
		return;
	}
	newPtr->data=val;
	newPtr->nextNode=NULL;
	prevPtr=NULL, currPtr=*np;
	while(currPtr!=NULL && val>currPtr->data)
	{
		prevPtr=currPtr;
		currPtr=currPtr->nextNode;
	}
	if(prevPtr==NULL)
	{
		newPtr->nextNode=*np;
		*np = newPtr;
	}
	else
	{
	  prevPtr->nextNode = newPtr;
	  newPtr->nextNode = currPtr;
	}
}

void node_delete(Node **np, int val)
{
	if(*np==NULL)
	{ 
		printf("Nothing to delete.\n");
		return;
	}
	else
	{
		Node *prevPtr, *currPtr;

		prevPtr=NULL, currPtr=*np;
		while(currPtr!=NULL && val!=currPtr->data)
		{
			prevPtr=currPtr;
			currPtr=currPtr->nextNode;
		}
		if(currPtr==NULL)
		{
			printf("Data not found!!\n");
			return;
		}
		else if(prevPtr==NULL)
		{
			*np=(*np)->nextNode;
			free(currPtr);
			return;
		}
		else
		{
			prevPtr->nextNode=currPtr->nextNode;
			free(currPtr);
			return;
		}
	}
}

void display_list(Node *np)
{
	if(np==NULL){ printf("List is empty.\n\n"); }
	else
	{
		printf("Linked list: \n");
		while(np!=NULL)
		{
			printf("%d-->", np->data);
			np=np->nextNode;
		}
		printf(" Nothing!!!\n");
	}
}
