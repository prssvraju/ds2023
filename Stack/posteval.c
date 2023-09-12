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
int isdigit(char);
double operate(char,double,double);
double eval(char[]);
int main()
{
    int exp[MAX];
    printf("Enter Post fix expression");
    scanf("%s",exp);
    printf("\nPost fix expression is %s",exp);
    printf("\nResult of Postfix expresson is %lf",eval(exp));
    return 0;
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
            printf("\n%c",c);
            opnd2=pop(&st);
            opnd1=pop(&st);
            value =operate(c,opnd1,opnd2);
             printf("\n%c\t%f\t%f\t%f",c,opnd1,opnd2,value);
            push(&st,value);
        }
    }
    return pop(&st);
}
int isdigit(char c)
{
    return (c>='0'&&c<='9');
}
double operate(char sym,double opnd1,double opnd2)
{
    switch(sym)
    {
        case '+':return (opnd1+opnd2);
        case '-':return (opnd1-opnd2);
        case '*':return (opnd1*opnd2);
        case '/':return (opnd1/opnd2);
        case '$':return (pow(opnd1,opnd2));
        default : printf("Invalid operator");
                  exit(0);
    }
}
void push(struct stack *stp,double ele)
{
    if(stp->top ==  MAX-1)
    {
        printf("Stack is overflow");
    }
    else
    {
        stp->top++;
        stp->items[stp->top]=ele;
    }
}
double pop(struct stack *stp)
{
    double ele;
    if(stp->top ==-1)
    {
        //printf("Stack is Under flow");
        return -1;
    }
    else
    {
        ele=stp->items[stp->top];
        stp->top--;
        return ele;
    }
    
}

