#include<stdio.h>
#define MAX 50
struct stack
{
    char items[MAX];
    int top;
};
void push(struct stack*,char);
char pop(struct stack*); 
char peek(struct stack*);
int isempty(struct stack*);
int isOperand(char);
int isp(char);
int icp(char);
void infixtopostfix(char[]);



int main()
{
    char infix[50];
    printf("Enter Infix string");
    scanf("%s",infix);
    printf("Infix string is %s\n",infix);
    infixtopostfix(infix);
    return 0;

}

void infixtopostfix(char infix[50])
{
    int i,j=0;
    char postfix[50];
    char symb,topsymb;
    struct  stack st;
    st.top = -1;
    
    for(i=0;(symb=infix[i])!='\0';i++)
    {
        if(isOperand(symb))
        {
            postfix[j]=symb;
            j++;
        }
        else if(symb == '(')
        {
            push(&st,symb);
        }
        else if(symb == ')')
        {
            topsymb = pop(&st);
            while(!isempty(&st)&& topsymb == ')')
            {
                postfix[j]=topsymb;
                j++;
                topsymb=pop(&st);
            }
        }
        else
        {
            while(!isempty(&st) && icp(symb)<=isp(peek(&st)))
            {
                topsymb = pop(&st);
                postfix[j]=topsymb;
                j++;
            }
            push(&st,symb);
        }
    }
    while(!isempty(&st))
    {
        topsymb=pop(&st);
        postfix[j]=topsymb;
        j++;
    }
    postfix[j]='\0';
    printf("Postfix string is %s\n",postfix);


}

void push(struct stack *stp,char c)
{
    if(stp->top == MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        stp->top=stp->top+1;
        stp->items[stp->top]=c;
    }
}
char pop(struct stack *stp)
{
    char ele;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        ele=stp->items[stp->top];
        stp->top=stp->top-1;
        return ele;
    }
}
char peek(struct stack *stp)
{
    char ele;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        ele=stp->items[stp->top];
        return ele;
    }
}
int isempty(struct stack *stp)
{
    if(stp->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isOperand(char c)
{
    if((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int icp(char c)
{
    switch(c)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;        
        case '$':
        case '^':return 3;
    }
}
int isp(char c)
{
    switch(c)
    {
        case '(':return 0;
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 2;        
        case '$':
        case '^':return 3;
    }
}