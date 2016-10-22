#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

typedef struct node
{
	int data;
	struct node *next;
}Node;

Node * deleteAllNegativeValues(Node *head);
Node *createNode(int);
void addToLast1(Node **head, int data);
void printRec(Node *head);

void main()
{
Node* head = NULL;
Node* newnode = NULL;
int i, data = 0;

srand(time(NULL));

for (i = 0; i<SIZE; i++)
	{
	data = rand() % (100 - (-100) + 1) - 100;
	addToLast1(&head, data);
	}

printRec(head);

newnode = deleteAllNegativeValues(head);
puts("\n");

printRec(newnode);
}

Node * deleteAllNegativeValues(Node *head)
{
Node*p = head, *p1, *p2;

while (p != NULL && p->data<0)
	{
	head = head->next;
	free(p);
	p = head;
	}

while (p != NULL)
	{
	p2 = p->next;

	if (p2 != NULL && p2->data<0)
		{
		p->next = p2->next;
		free(p2);
		}
	else
		p = p->next;
	}

return head;
}

Node *createNode(int data)
{
Node *temp = (Node*)malloc(sizeof(Node));

temp->data = data;

temp->next = NULL;
return temp;
}

void addToLast1(Node **head, int data)
{
Node *p = *head;
Node *temp = createNode(data);

if (*head == NULL)
	{
	*head = temp;
	return;
	}

while (p->next != NULL)
	p = p->next;
p->next = temp;
}

void printRec(Node *head)
{
if (head == NULL)
	return;

printf("%d\t", head->data);
printRec(head->next);
}