#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int data;
	struct Node *next;
}node;

node * addToLast(node *, int);
node * createNode(int);
void printList(node *);
node * deleteMinValue(node *);

void main()
{
node* head = NULL;
int data = 0;
	
printf("Please enter numbers : ");

while (data >= 0)
	{
	scanf("%d", &data);

	if (data<0)
		break;

	head = addToLast(head, data);
	printList(head);
	}
	
printf("\n\nValue is below 0, program stops\n\n\n");

head = deleteMinValue(head);
printf("The new linked list : \n\n");
printList(head);
printf("\n\n");
}

node *addToLast(node *head, int data)
{
node *p = head;
node *temp = createNode(data);

if (head == NULL)
	return temp;

while (p->next != NULL)
	p = p->next;

p->next = temp;

return head;
}

node *createNode(int data)
{
node *temp = (node *)malloc(sizeof(node));

temp->data = data;
temp->next = NULL;

return temp;
}

void printList(node *head)
{
node *p = head;

while (p != NULL)
	{
	printf("%d->", p->data);
	p = p->next;
	}

printf(" NULL   ");
}

node *deleteMinValue(node *head)
{
node*p = head, *before = head, *min = head;

if (head == NULL)
	return NULL;
	
if (head->next == NULL)
	{
	free(head);
	return NULL;
	}

while (p != NULL)
	{
		
	if (p->next != NULL && p->next->data<min->data)
		{
		before = p;
		min = p->next;
		}
		
	p = p->next;
	}

if (min == head)
	{
	head = head->next;
	free(min);
	return head;
	}

before->next = min->next;
free(min);
	
return head;
}