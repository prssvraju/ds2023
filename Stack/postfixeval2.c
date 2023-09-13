/*postfix evaluation*/
#define MAX 20
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct stack
{
	int top;
	double items[MAX];
};
struct stack s;
double oper(char,double,double);
void push(struct stack *,double);
double pop(struct stack *);
int empty(struct stack *);
double eval(char []);
int isdigit(char);
int main()
{

	char expr[MAX];
	//clrscr();
	s.top=-1;
	printf("enter the postfix expression");
	scanf("%s",expr);
	printf("\nthe original postfix expression is %s",expr);
	printf("\n%lf",eval(expr));
    return 0;
 }

double eval(char expr[])
{
	int i;
	char c;
	double opnd1,opnd2,value;

	for(i=0;(c=expr[i])!='\0';i++)
	{
		if(isdigit(c))
		{
			push(&s,(double)c-'0');
		}
		else
		{
			printf("\n%c",c);
			opnd2=pop(&s);
			opnd1=pop(&s);
			value=oper(c,opnd1,opnd2);
			push(&s,value);

		}

	}
	return(pop(&s));
}
int isdigit(char symb)
{
	return(symb>='0'&&symb<='9');
}
double oper(char symb,double op1,double op2)
{
	switch(symb)
	{
		case '+':return(op1+op2);

		case '-':return(op1-op2);

		case '*':return(op1*op2);

		case '/':return(op1/op2);

		case '$':return(pow(op1,op2));

		default:printf("\nillegal operation");
			exit(0);
	}
}
void push(struct stack *st,double a)
{
	if(st->top==MAX-1)
	{
		printf("\nstack is overflow");

	}
	else
	{
		st->top++;
		st->items[st->top]=a;
	}
}
double pop(struct stack *st)
{
	double a;
	if(st->top == -1)
		return -1;
	else
	{
		a=st->items[st->top];
		st->top--;
		return a;
	}
}
