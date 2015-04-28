#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int data;
	struct t_node *nextNode;
}Node;

void stack_push(Node **, int);
void stack_pop(Node **);
void stack_top(Node *);
void stack_display(Node *);

int main(void)
{
	int method, val;
	Node *head;

	head=NULL;
	puts("Input a method(1 and a value to push, 0 to pop, 2 to show the top) or -1 to quit:");
	while(scanf("%d", &method))
	{
		switch(method)
		{
			case -1:
				while(head!=NULL){ stack_pop(&head); }
				return 0;
			case 0:
				stack_pop(&head);
				break;
			case 1:
				scanf("%d", &val);
				stack_push(&head, val);
				break;
			case 2:
				stack_top(head);
				break;
			default:
				puts("Error  Method!!");
				break;
		}
		stack_display(head);
	}
}

void stack_push(Node **head, int val)
{
	Node *curPtr, *prevPtr, *newPtr;

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

void stack_pop(Node **head)
{
	Node *curPtr, *prevPtr;

	curPtr=*head, prevPtr=NULL;
	if(curPtr!=NULL)
	{
		while(curPtr->nextNode!=NULL)
		{
			prevPtr=curPtr;
			curPtr=curPtr->nextNode;
		}
		if(prevPtr==NULL){ *head=NULL; }
		else{ prevPtr->nextNode=NULL; }
		free(curPtr);
	}
	else{ puts("Nothing to pop."); }
}

void stack_top(Node *head)
{
	Node *curPtr, *prevPtr;
	
	curPtr=head, prevPtr=NULL;
	while(curPtr!=NULL)
	{ 
		prevPtr=curPtr;
		curPtr=curPtr->nextNode; 
	}
	if(prevPtr==NULL){ puts("There is nothing on the stack."); }
	else{ printf("%d\n", prevPtr->data); }
}

void stack_display(Node *head)
{
	Node *curPtr;
	
	curPtr=head;
	while(curPtr!=NULL)
	{
		printf("%d-->", curPtr->data);
		curPtr=curPtr->nextNode;
	}
	printf("NULL\n");
}
