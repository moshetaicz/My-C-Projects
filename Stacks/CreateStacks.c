#include <stdio.h>
#include <stdlib.h>

#define N 100
typedef int type;

typedef struct Stack
{
	
type arr[N];
type top;

}stack;

stack *createStack();
void push(stack *, type data);
type pop(stack *);
type top(stack *);
int isEmpty(stack *);
int isFull(stack *);


void main()
{
int num;
stack *s = createStack();
stack *s2 = createStack();

printf("Please enter a number : ");
scanf("%d", &num);
printf("\n");

// Create First Stack//
while (num != 0)
	{
	push(s, num % 10);
	num /= 10;
	}

// Create Second Stack//
while (!isEmpty(s))
	push(s2, pop(s));

printf("Answer : ");

while (!isEmpty(s2))
	printf("%d", pop(s2));

printf("\n\n");
}

stack *createStack()
{
stack *s = (stack*)malloc(sizeof(stack));
s->top = -1;
return s;
}

void push(stack *s, type data)
{
if (isFull(s))
	{
	printf("The Stack Is Full");
	return;
	}

s->top++;
s->arr[s->top] = data;
}

type pop(stack *s)
{
int temp;

if (isEmpty(s))
	{
	printf("The Stack Is Empty");
	return -1;
	}
	
temp = s->arr[s->top];
s->top--;
return temp;
}

type top(stack *s)
{
if (isEmpty(s))
	{
	printf("The Stack Is Empty");
    return -1;
	}

return s->arr[s->top];

}

int isEmpty(stack *s)
{

/* if(s->top == -1)
return1;
return 0; */

return s->top == -1;
}

int isFull(stack *s)
{
return s->top == N;
}