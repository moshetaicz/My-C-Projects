#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

/* This code gets array of integers and make a new array in the size of the amount of positive integers in the original array */

void main()
{
int arr[SIZE] = { -1,-2,-3,-4,-5,6,7,8,9,10 };
int *p;
int i, counter = 0, j = 0;

for (i = 0; i<SIZE; i++)
	{
	if (arr[i]>0)
		counter++;
	}

p = (int*)malloc(sizeof(int)*counter);

if (p == NULL)
	exit(1);

for (i = 0; i<SIZE; i++)
	{
	if (arr[i]>0)
		p[j++] = arr[i];
	}

printf("The size of the original arr : ");
for (i = 0; i<SIZE; i++)
	printf("%d  ", arr[i]);

printf("\n\nIs : [%d]", SIZE);

printf("\n\n\n");

printf("The size of the new arr : ");
for (i = 0; i<counter; i++)
	printf("%d  ", p[i]);

printf("\n\nIs : [%d]", counter);

printf("\n\n");

free(p);
}