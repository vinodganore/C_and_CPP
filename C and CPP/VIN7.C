#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define max 10
struct post
{
	char stk[max];
	int top;
	char expr[max];
};
main()
{
	struct post p;
	char infix[max];
	clrscr();
	printf("enter the infix expression\n");
	gets(infix);
	convert(infix,&p);
	printf("postfix expression is........%s",p.expr);
getch();
}
int convert(char *in,struct post *q)
{
	char opr;
	char *pt=q->expr;
	while(*in!='\0')
	{
		if(*in== ' ' || *in=='\t')
			in++;
		if(isdigit(*in) || isalpha(*in))
		{
			while(isdigit(*in)||isalpha(*in))
			{
				*pt=*in;
				in++;
				pt++;
			}
		}
		if(*in=='(')
		{
			push(q,*in);
			in++;
		}
		if(isoperator(*in))
		{
			if(q->top!=-1)
			{
				opr=pop(q);
				while(priority(opr)>=priority(*in))
				{
					*pt=opr;
					pt++;
					opr=pop(q);
				}
				push(q,opr);
			}
			push(q,*in);
			in++;
		}
		if(*in==')')
		{
			opr=pop(q);
			while(opr!='(')
			{
				*pt=opr;
				pt++;
				opr=pop(q);
			}
			in++;
		}
	}

	while(q->top!=-1)
	{
		opr=pop(q);
		*pt=opr;
		pt++;
	}
	*pt='\0';
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
 push(struct post *q,char c)
{
	if(q->top==max-1)
	{
		printf("stack is overflow");
		return;
	}
	q->top++;
	q->stk[q->top]=c;
}
pop(struct post *q)
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





