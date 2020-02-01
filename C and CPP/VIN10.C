#include<stdio.h>
#include<conio.h>
#define isempty top ==NULL
typedef struct stack
{
	int data;
	struct stack *next;
}node;
node *top;
void push(int item)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL)
	{
		printf("\n memory is not allocated properly");
		return;
	}
	temp->data=item;
	temp->next=top;
	top=temp;
}
int pop()
{
	node *temp;
	int item;
	if(isempty)
	{
		printf("\n stack is empty");
		return -1;
	}
	temp=top;
	item=temp->data;
	top=top->next;
	free(temp);
	return item;
}
int peek()
{
	if(isempty)
	{
		printf("stack is empty");
		return -1;
	}
	else
		return top->data;
}
void display()
{
	node *a;
	if(isempty)
		printf("\n no items to display");
	else
	{
		printf("\n the data is");
		for(a=top;a!=NULL;a=a->next)
			printf("\n %d",a->data);
	}
}
int length()
{
	node *a,*temp;
	int size=0;
	for(a=temp;a!=NULL;a=a->next)
		size++;
	return size;
}
void main()
{
	int choice,item,i;
	while(1)
	{
		printf("\n\n 1.push\n 2.pop \n 3.peek \n 4.isempty \n 5.display \n 6.length \n 7.exit");
		printf("\n\nenter u r choice=");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter the element to push");
				scanf("%d",&item);
				push(item);
				break;
			case 2:if((i=pop())!=-1)
				printf("the deleted ele is..%d",i);
				break;
			case 3: if((i==peek())!=-1)
				printf("top most ele is ....%d",i);
				break;
			case 4: if(isempty)
					printf("\n the stack is empty");
				else
					printf("\n the stack is not empty");
				break;
			case 5: display();
				break;
			case 6: printf("\n the size is %d",length());
				break;
			case 7: exit(0);
			default: printf("entered wrong choice");
		}
	}
}



