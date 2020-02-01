#include<stdlib.h>
#include<conio.h>
#include<dos.h>
void main()
{
int *marks=(int*)malloc(4*sizeof(int));
int mark,i,n=0,size=3;clrscr();
printf("\nenter the marks (enter -1 for to stop)");
scanf("%d",&mark);
while(mark!=-1)
{
	if(n>=size)
	{
		size+=4;
		printf("realloc 4 more maks\n");
		marks=(int*)realloc(marks,size*sizeof(int));
		if(marks==(int*)NULL)
		{
			printf("not enough memory \n" );
			exit(1);
		}
		else
			printf("\nenter marks for 4 student(enter -1 for stop)");
	}
	marks[n]=mark;
	//fflush(stdin);
	scanf("%d",&mark);
	n++;
}
printf("the size is....%d\n",sizeof(marks));
free(marks);
printf("the marks entered are ...........\n");
for(i=0;i<n;i++)
	printf("the marks are     %d\n\n",marks[i]);
getch();
}









































































