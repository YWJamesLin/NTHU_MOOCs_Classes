#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int data;
	struct t_node *nextNode;
}Node;

void queue_enqueue(Node **, int);
void queue_dequeue(Node **);
void queue_print(Node *);

int main(void)
{
	int method, val;
	Node *head;
	
	head=NULL;
	while(1)
	{
		puts("Input the method(1 and a value to enqueue, 0 to dequeue, 2 to show the queue, -1 to quit):");
		scanf("%d", &method);
		switch(method)
		{
			case -1:
				while(head!=NULL){ queue_dequeue(&head); }
				return 0;
			case 0:
				queue_dequeue(&head);
				break;
			case 1:
				scanf("%d", &val);
				queue_enqueue(&head, val);
				break;
			case 2:
				queue_print(head);
				break;
			default:
				puts("Error Method.");
				break;
		}
	}
}

void queue_enqueue(Node **head, int val)
{
	Node *newPtr, *curPtr, *prevPtr;

	newPtr=(Node *)malloc(sizeof(Node));
	newPtr->data=val;
	newPtr->nextNode=NULL;
	curPtr=*head, prevPtr=NULL;
	while(curPtr!=NULL)
	{
		prevPtr=curPtr;
		curPtr=curPtr->nextNode;
	}
	if(prevPtr==NULL){ *head=newPtr; }
	else{ prevPtr->nextNode=newPtr; }
}

void queue_dequeue(Node **head)
{
	Node *tmpPtr;
	
	if(*head==NULL)
	{
		puts("Nothing to dequeue.");
		return;
	}
	else
	{
		tmpPtr=*head;
		*head=(*head)->nextNode;
		free(tmpPtr);
	}
}

void queue_print(Node *head)
{
	Node *curPtr;

	curPtr=head;
	while(curPtr!=NULL)
	{
		printf("%d-->", curPtr->data);
		curPtr=curPtr->nextNode;
	}
	puts("NULL.");
}
