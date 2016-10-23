#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* In this code i made a dynamic allocation matrix that get from the user No of rows and No of cols and generate random number.
   after first matrix comes the second one which her diagonal sums each row. */

int SumArr(int *arr, int size);
void main()
{
int **arr;
int rows, cols, i, j;
srand(time(NULL));

printf("Enter No of Rows : ");
scanf("%d", &rows);

printf("Enter No of Cols : ");
scanf("%d", &cols);
	
printf("\n\n");

arr = (int **)malloc(sizeof(int *)*rows);

for (i = 0; i<rows; i++)
	arr[i] = (int *)malloc(sizeof(int)*cols);

for (i = 0; i<rows; i++)
	for (j = 0; j<cols; j++)
		arr[i][j] = rand()%10 + 1;

for (i = 0; i<rows; i++)
	{
	for (j = 0; j<cols; j++)
		printf("%d\t", arr[i][j]);
	printf("\n");
	}

printf("\n");

for (i = 0; i<rows; i++)
	arr[i][i] = SumArr(arr[i], rows);


for (i = 0; i<rows; i++)
	{
	for (j = 0; j<cols; j++)
		printf("%d\t", arr[i][j]);
	printf("\n");
	}
}

int SumArr(int *arr, int size)
{
int i,sum = 0;

for (i = 0; i<size; i++)
	sum += arr[i];

return sum;
}