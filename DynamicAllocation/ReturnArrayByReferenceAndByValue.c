#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* This code gets array size from the user and prints to arrays,
one that was created by value and one that was created by Reference */

void byValue(int, char **);
char *byReference(int size);

void main()
{
int size,i;
char *arr,*arrRef;
srand(time(NULL));

do
{
printf("Please enter the array size : ");
scanf("%d", &size);
}while (size<0);

byValue(size, &arr);
arrRef = byReference(size);

printf("\n\n");

printf("By Value : ");
for (i = 0; i < size; i++)
    printf("%c  ", arr[i]);

printf("\n\n");

printf("By Reference : ");
for (i = 0; i < size; i++)
	printf("%c  ", arrRef[i]);

printf("\n\n\n");
	
free(arr);
free(arrRef);
}

void byValue(int size, char **arr)
{
int i;
	
*arr = (char*)malloc(sizeof(char)*size);

if (!*arr)
	exit(0);

for (i = 0; i < size; i++)
(*arr)[i] = rand() % ('z' - 'a' + 1) + 'a';
}

char *byReference(int size)
{
int i;
char *arr2;
	
arr2 = (char*)malloc(sizeof(char)*size);
	
if (!*arr2)
	exit(0);

for (i = 0; i < size; i++)
arr2[i] = rand() % ('z' - 'a' + 1) + 'a';

return arr2;
}