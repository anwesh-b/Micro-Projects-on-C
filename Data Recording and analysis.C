/*Program to store data of marks of student and print it.
Author:Anwesh Budhathoki
Date:2019/03/12
About: This program takes the name, roll no and marks of 5 subjects. Then it arranges the roll no in ascending order and prints all the data.*/



#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct info{
	char name[30];
	int roll_no;
	struct markofstu{
		int maths;
		int dl;
		int iit;
		int c;
		int phy;
	}marks;
}inf[1000];
void main(){
	struct info data,log;
	int n,i,j;
	clrscr();
	printf("Enter total number of students");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		clrscr();
		printf("\nEnter name of student");
		scanf("%s",&inf[i].name);
		printf("\nEnter your roll number:");
		scanf("%d",&inf[i].roll_no);
		printf("\nEnter your marks in Maths");
		scanf("%d",&inf[i].marks.maths);
		printf("\nEnter your marks in Digital Logic");
		scanf("%d",&inf[i].marks.dl);
		printf("\nEnter your marks in IIT");
		scanf("%d",&inf[i].marks.iit);
		printf("\nEnter your marks in C Programming");
		scanf("%d",&inf[i].marks.c);
		printf("\nEnter your makrs in Physics");
		scanf("%d",&inf[i].marks.phy);
	}
	for(i=0;i<n;i++)
	{
		for(j=(i+1);j<n;j++)
		{
			if(inf[i].roll_no>inf[j].roll_no)
			{
				log=inf[i];
				inf[i]=inf[j];
				inf[j]=log;
			}
		}
	}
	clrscr();
	printf("\n\nRoll No\tName of Student\tMaths\tDL\tIIT\tC Prog\tPhysics");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%s\t\t%d\t%d\t%d\t%d\t%d",inf[i].roll_no,inf[i].name,inf[i].marks.maths,inf[i].marks.dl,inf[i].marks.iit,inf[i].marks.c,inf[i].marks.phy);
	}
	getch();
}
