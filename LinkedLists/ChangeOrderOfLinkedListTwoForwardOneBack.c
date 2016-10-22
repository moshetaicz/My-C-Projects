#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

int data;
struct Node *next;
struct Node *prev;

}node;

void printList(node *);
node *addToLast(node *, int);
node *createNode(int);
void print(node *);

void main()
{
node  *head = NULL;

head = addToLast(head, 1);
head = addToLast(head, 2);
head = addToLast(head, 3);
head = addToLast(head, 4);
head = addToLast(head, 5);
head = addToLast(head, 6);
head = addToLast(head, 7);

printList(head);
print(head);
}

void printList(node *head)
{
node *p = head;

printf("NULL");

if (head == NULL)
	return;

while (p != NULL)
	{
	printf("<-%d->", p->data);
	p = p->next;
	}

printf("NULL\n");
}

node *addToLast(node *head, int data)
{
node *temp = createNode(data);
node *p = head;

if (head == NULL)
	return temp;

while (p->next != NULL)
	p = p->next;

p->next = temp;
temp->prev = p;

return head;
}

node *createNode(int data)
{
node *temp = (node*)malloc(sizeof(node));

temp->data = data;
temp->next = NULL;
temp->prev = NULL;
}

void print(node *head)
{
node *p = head;

if (head == NULL)
	return;

printf("NULL");

while (p != NULL)
	{
	printf("<-%d->", p->data);
	
	if (p->next != NULL)
		{
		p = p->next->next;
		if (p == NULL)
			return;

		printf("<-%d->", p->data);
		p = p->prev;
		}
	else
		p = p->next;
	}
}