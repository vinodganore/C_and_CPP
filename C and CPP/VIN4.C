#include<stdio.h>
#define max 10
void push(char);
int pop();
int top=-1;
char stk[10],exp[30],buf[30],ch;
int k,h;
int i=0,j=0,k   ;
void main()
{

clrscr();
printf("enter expression");
scanf("%s",exp);
printf("the given exp is %s",exp);
while (exp[i]!='\0')
{     ch=exp[i];
      if(ch=='(')
      {
	push(ch);
      }
      if(ch==')')
      {
	stk[i]=pop();
      }
      if(ch>='a' && ch<='z')
      {
	buf[j]=ch;
	j++;
      }
      push(ch);
      i++;
}

printf("\nthe expression is");
for(i=0;buf[i]!='\0';i++)
printf("%c",buf[i]);

getch();
}
void push(char ch)
{    top++;
	if(p(h=pop())>=p(ch))
	stk[top]=h;
	else
		buf[i]=ch;
}
int pop()
{
k=buf[top];
top--;
return k;
}





















