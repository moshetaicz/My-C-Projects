#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define CLASS_SIZE 40
#define GRADES 10
#define NAME_LEN 11
#define COURSES 10

typedef struct Student
{
	
long id;
char name[NAME_LEN];
int grades[GRADES];
float gradeAvgArr;

}student;

typedef struct Course
{

int courseNumber;
char name[20];
int lvl;
float courseAvg;

}course;

const char *names[] = { "Momo","Dudo","Rivka","Ben","Dani","Yaron","Rami","Moshe","Yafa","Sapir",
"Momo1","Dudo1","Rivka1","Ben1","Dani1","Yaron1","Rami1","Moshe1","Yafa1","Sapir1",
"Momo2","Dudo2","Rivka2","Ben2","Dani2","Yaron2","Rami2","Moshe2","Yafa2","Sapir2",
"Momo3","Dudo3","Rivka3","Ben3","Dani3","Yaron3","Rami3","Moshe3","Yafa3","Sapir3" };

const char *Course[] = { "Math","Geography","Psychology" ,"Science","Art","Physics","Engineering","Web","Office","Teaching" };

void printStudent(student *ptr);
void insertStudentsDetails(student arr[], int size);
void insertCoursesDetails(course arr[], int size);
void printCourse(course *ptr);
void courseAvg(course arrc[], student arrs[], int sizec, int sizes);
void excellentStudents(student arrs[], course arrc[], int sizes);
void mostDifficulteCourse(course arr[], int size);
void studentsFailed(student arr[], int sizes, int sizec);

student arrs[CLASS_SIZE];
course arrc[COURSES];

void main()
{
int i;

srand(time(NULL));

insertStudentsDetails(arrs, CLASS_SIZE);
insertCoursesDetails(arrc, COURSES);
courseAvg(arrc, arrs, COURSES, CLASS_SIZE);

for (i = 0; i<CLASS_SIZE; i++)
	printStudent(&arrs[i]);

for (i = 0; i<COURSES; i++)
	printCourse(&arrc[i]);

excellentStudents(arrs, arrc, CLASS_SIZE);
puts("\n***************************");
mostDifficulteCourse(arrc, COURSES);
puts("\n***************************");
studentsFailed(arrs, CLASS_SIZE, COURSES);
}

void insertStudentsDetails(student arr[], int size)
{
int i, j;
float avg = 0;

for (i = 0; i<size; i++)
	{
	strcpy(arr[i].name, names[i]);
	arr[i].id = 11111 + rand() % 100000;

	for (j = 0; j<GRADES; j++)
		arr[i].grades[j] = rand() % 56 + 45;
	}

for (i = 0; i < size; i++)
	{
		for (j = 0; j<GRADES; j++)
           avg = avg + arr[i].grades[j];

	avg = avg / 10;
	arr[i].gradeAvgArr = avg;
	avg = 0;
	}
}

void printStudent(student *ptr)
{
int i;

printf("Student Name : %s\n", ptr->name);
printf("Id : %d\n", ptr->id);
printf("Student Grades :");

for (i = 0; i<GRADES; i++)
	printf("%4d", ptr->grades[i]);

printf("\nStudent Grades Avg : %.2f", ptr->gradeAvgArr);

puts("\n\n#####################################\n");
}

void insertCoursesDetails(course arr[], int size)
{
int i;

for (i = 0; i<size; i++)
	{
	arr[i].courseNumber = i;
	strcpy(arr[i].name, Course[i]);
	arr[i].lvl = rand() % 3 + 1;
	}
}

void printCourse(course *ptr)
{

printf("Course Number: %d\n", ptr->courseNumber);
printf("Course Name: %s\n", ptr->name);
printf("Course Lavel: %d\n", ptr->lvl);
printf("Course Avg: %.2f\n", ptr->courseAvg);
puts("\n-----------------------------------------\n");

}

void courseAvg(course arrc[], student arrs[], int sizec, int sizes)
{
int i, j;
float avgtemp = 0;

for (i = 0; i<sizec; i++)
	{
	
	for (j = 0; j<sizes; j++)
		avgtemp += arrs[j].grades[i];

	avgtemp /= sizes;
	arrc[i].courseAvg = avgtemp;
	avgtemp = 0;
	}
}

void excellentStudents(student arrs[], course arrc[], int sizes)
{
int i, j;
float avgtemp = 0;

puts("Excellent Students :\n");

for (i = 0; i<sizes; i++)
	{
		
	for (j = 0; j<COURSES; j++)
		{
		if (arrc[j].lvl == 1)
			avgtemp += arrs[i].grades[j];

		else if (arrc[j].lvl == 2)
			avgtemp = avgtemp + arrs[i].grades[j] * 1.1;

		else if (arrc[j].lvl == 3)
			avgtemp = avgtemp + arrs[i].grades[j] * 1.2;
		}

    avgtemp /= COURSES;
		
    if (avgtemp>85)
	   {
	   printf("Student Name: %s\t", arrs[i].name);
	   printf("Student Avg: %.2f\n", avgtemp);
	   }
	
    avgtemp = 0;
	}
}

void mostDifficulteCourse(course arrc[], int size)
{
int i, minindex;
float arr[10] = { 0 };

puts("\nMost Difficulte Course :\n");

for (i = 0; i<size; i++)
	arr[i] = arrc[i].courseAvg;

minindex = 0;

for (i = 0; i<size; i++)
	if (arr[i]<arr[minindex])
		minindex = i;

printf("Course Name : %s  |  ", arrc[minindex].name);
printf("Course Avg : %.2f\n", arr[minindex]);
}

void studentsFailed(student arrs[], int sizes, int sizec)
{
int i, j, countfail = 0;

puts("\nStudents Failed :\n");

for (i = 0; i<sizes; i++)
	{
	for (j = 0; j<sizec; j++)
		if (arrs[i].grades[j]<56)
			countfail++;

	if (countfail >= 3)
		{
		printf("Student Name: %s\t", arrs[i].name);
		printf("Numbers of Fail : %d\n", countfail);
		}
	countfail = 0;
	}
}