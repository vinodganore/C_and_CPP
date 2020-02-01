#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 8
struct pre
{
	char stk[max];
	int top;
	char expr[max];
};
main()
{
	struct pre p;
	char infix[max];
	clrscr();
	printf("enter the infix expression\n");
	gets(infix);
	convert(infix,&p);
	printf("prefix expression is........%s",p.expr);
getch();
}
int convert(char *in,struct pre *q)
{
	char *pt;
	char opr;
	int l=strlen(in);
	in=in+(l-1);
	pt=q->expr+(l-1);
	*(q->expr+l)='\0';
	while(l!=0)
	{
		if(*in== ' ' || *in=='\t')
		  {	l--;in--;   }
		  if(isdigit(*in) || isalpha(*in))
		  {
			while(isdigit(*in)||isalpha(*in))
			{
				*pt=*in;
				in--;l--;
				pt--;
			}
		}
		if(*in==')')
		{
			push(q,*in);
			in--;l--;
		}
		if(isoperator(*in))
		{
			if(q->top!=-1)
			{
				opr=pop(q);
				while(priority(opr)>priority(*in))
				{
					*pt=opr;
					pt--;
					opr=pop(q);
				}
				push(q,opr);
			}
			push(q,*in);
			in--;
			l--;
		}
		if(*in=='(')
		{
			opr=pop(q);
			while(opr!=')')
			{
				*pt=opr;
				pt--;
				opr=pop(q);
			}
			in--;
			l--;
		}
	}

	while(q->top!=-1)
	{
		opr=pop(q);
		*pt=opr;
		pt--;
	}
	pt++;
	strcpy(q->expr,pt);
}
int priority(char c)
{
	if(c=='$')
		return 3;
	if(c=='*'||c=='/'||c=='%')
		return 2;
	if(c=='+'||c=='-')
		return 1;
	return 0;
}
isoperator(char ch)
{
	char str[]="*+/%-$";
	char *p;
	p=str;
	while(*p!='\0')
	{
		if(*p==ch)
		    return 1;
		p++;
	}
	return 0;
}
 push(struct pre *q,char c)
{
	if(q->top==max-1)
	{
		printf("stack is overflow");
		return;
	}
	q->top++;
	q->stk[q->top]=c;
}
pop(struct pre *q)
{
	 char item;
	 if(q->top==-1)
	 {
		printf("stack is empty");
		return -1;
	 }
	 item=q->stk[q->top];
	 q->top--;
	 return item;
}