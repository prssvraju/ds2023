#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 20
struct stack
{
    double items[MAX];
    int top;
};
void push(struct stack*,double);
double pop(struct stack*);
double oper(char,double,double);

int isdigit(char);

double eval(char[]);
int main()
{
    char exp[MAX];
    printf("Entet the expression");
    scanf("%s",exp);
    printf("Expression is %s",exp);
    printf("Result is  %lf",eval(exp));
}
double eval(char exp[MAX])
{
    int i;
    char c;
    double opnd1,opnd2,value;
    struct stack st;
    st.top=-1;
    for(i=0;(c=exp[i])!='\0';i++)
    {
        if(isdigit(c))
        {
            push(&st,(double)c-'0');
        }
        else
        {
            opnd2=pop(&st);
            opnd1=pop(&st);
            value=oper(c,opnd1,opnd2);
            push(&st,value);
        }
    }
    return pop(&st);
}
void push(struct stack *stp,double ele)
{
    if(stp->top==MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        stp->top=stp->top+1;       
        stp->items[stp->top]=ele;
    }
}
double pop(struct stack *st)
{
    double ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        st->top=st->top-1;
        return ele;
    }
}
int isdigit(char c)
{
    return (c>='0'&&c<='9');
}
double oper(char c,double opnd1,double opnd2)
{
    switch(c)
    {
        case '+': return(opnd1+opnd2);gb
        case '-': return(opnd1-opnd2);
        case '*': return(opnd1*opnd2);
        case '/': return(opnd1/opnd2);
        case '$': return(pow(opnd1,opnd2));
        default : printf("Invalid");    
                  exit(0);
    }
}