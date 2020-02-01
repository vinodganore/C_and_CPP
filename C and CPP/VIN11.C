#include<stdio.h>
#include<conio.h>
#define max 4
int front=-1,rear=-1,que[max];
void insert()
{           int ele;
	if(rear>=max-1)
	{
		printf("overflow");
		return;
	}
	else
	{        rear++;
	printf("enter ele at %d pos ",rear);
	scanf("%d",&ele);
	que[rear]=ele;
	}
	if(front==-1)
		front=0;
}
int del()
{               int ele;
	if(front==-1)
	{
		printf("underflow");
		return;
	}
	else
	{
	       ele=que[front];
	 /*      if(rear==front)
	       {
		front=-1;
		rear=-1;
		}
		else   */
		front++;
	       return ele;
	}
}
void disp()
{
int i;
for(i=front;i<=rear;i++)
printf("\n ele at %d is %d",i,que[i]);
}
void main()
{
int i;
clrscr();
for(i=0;i<max;i++)
{
insert();
}
disp();
printf("\ndel is  %d",del());
printf("\ndel is  %d",del());
printf("\ndel is  %d",del());
printf("\ndel is  %d",del());
printf("\ndel is  %d",del());
getch();
}
