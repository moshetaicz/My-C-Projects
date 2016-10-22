#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{

int data;
struct Node *next;
struct Node *prev;

}node;

void printReverse(node *);
void printList(node *);
node *addToFirst(node *, int);
node *addToLast(node *, int);
node *createNode(int);

void main()
{
node  *head = NULL;
//node *temp;

//head = createNode(7);
//temp = createNode(8);

head = addToFirst(head, 1);
head = addToFirst(head, 2);
head = addToFirst(head, 3);
head = addToFirst(head, 4);
head = addToFirst(head, 5);
head = addToFirst(head, 6);

//head -> next = temp;
//temp ->prev = head;

printList(head);
printReverse(head);
}

void printReverse(node *head)
{
node *p = head;

printf("NULL");

if (head == NULL)
	return;

for (; p->next != NULL; p = p->next);

while (p != NULL)
	{
	printf("<-%d->", p->data);
	p = p->prev;
	}

printf("NULL\n");
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

node *addToFirst(node *head, int data)
{
node *temp = createNode(data);

if (head == NULL)
	return temp;

temp->next = head;
head->prev = temp;

return temp;
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