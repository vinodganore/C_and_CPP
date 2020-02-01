#include<stdio.h>
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};
struct tree *root=NULL;
struct tree *create();
void display(struct tree *);
void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);
void main()
{
int ch;
do
{
	xy:
		clrscr();
		printf("enter 1.create\n 2.display\n 3.exit");
		switch(ch)
		{
			case 1: root=create();
				ch=0;
				goto xy;
			case 2:display(root);
				ch=0;
				goto xy;
			case 3:exit(0);
		}
		printf("enter ur choice"0;
		scanf("%d",&ch);
}while(ch!=3);
getch();
}
struct tree *create()
{
struct tree *first,*head,*prev,*temp;
int n,x,i;
clrscr();
printf("how many node you want to create");
scanf("%d",&n);
printf("enter data int 1 st node");
scanf("%d",&x);
head=(struct tree *)malloc(sizeof(struct tree));
head->data=x;
head->left=NULL;
head->right=NULL;
for(i=0;i<n;i++)
{
	printf("\n enter data into %d node",i+1);
	scanf("%d",&x);
	first=head;
	while(first!=NULL)
	{
		prev=first;
		if(first->data>x)
			first=first->left;
		else
			first=first->right;
	}
	temp=(struct tree *)malloc(sizeof(struct tree));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;
	if(prev->data>x)
		prev->left=temp;
	else
		prev->right=temp;
}
return head;
}
void display(struct tree *ptr)
{
	int t;
	clrscr();
	printf("\n enter 1.preorder\n 2.inorder\n 3.postorder\n enter ur choice");
	scanf("%d",&t);
	switch(t)
	{
		case 1: preorder(ptr);
			break;
		case 2: inorder(ptr);
			break;
		case 3 postorder(ptr);
			break;
		default: printf("error............");
	}
}
void preorder(struct tree *ptr)
{
	int top=0;
	struct tree *first=ptr,*stack[20];
	stack[top]=NULL;
	while(first!=NULL)
	{
		printf("%d \t ",first->data);
		if(first->right!=NULL)
		{
			top=top++;
			stack[top]=first->right;
		}
		if(first->left!=NULL)
			first=first->left;
		else
		{
			first=stack[top];
			top--;
		}
	}
}
void inorder(struct tree *ptr)
{
	struct tree *stack[20];
