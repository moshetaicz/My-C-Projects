#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 8

typedef struct node
{
	int data;
	struct node *next;
}Node;

void splitArrToLists(int *, Node **, Node **, int);
void addToLast(Node **, int);
Node *createList(int);
void printList(Node *);

void main()
{
	int i, arr[SIZE];
	Node *a = NULL;
	Node *b = NULL;

	srand(time(NULL));

	for (i = 0; i<SIZE; i++)
		arr[i] = rand() % 50 + 1;


	printf("Original Arr : ");
	for (i = 0; i<SIZE; i++)
		printf("%d\t", arr[i]);

	printf("\n\n\n");

	splitArrToLists(arr, &a, &b, SIZE);

	printf("Even Arr : ");
	printList(a);

	printf("\n\n");

	printf("Odd Arr : ");
	printList(b);

	printf("\n\n");
}

void splitArrToLists(int *arr, Node **a, Node **b, int size)
{
	int i;

	for (i = 0; i<size; i++)
	{
		if (arr[i] % 2 == 0)
			addToLast(a, arr[i]);
		else
			addToLast(b, arr[i]);
	}
}

void addToLast(Node **head, int data)
{
	Node *p = *head;
	Node *temp = createList(data);

	if (*head == NULL)
	{
		*head = temp;
		return;
	}

	while (p->next != NULL)
		p = p->next;
	p->next = temp;
}

Node *createList(int data)
{
	Node *temp = (Node*)malloc(sizeof(Node));

	temp->data = data;

	temp->next = NULL;
	return temp;
}

void printList(Node *head)
{
	Node *p = head;

	while (p != NULL)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n\n");
}