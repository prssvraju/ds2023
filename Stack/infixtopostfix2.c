#include<stdio.h>
#define MAX 50
struct stack
{
    char items[MAX];
    int top;
};
struct stack st;
void push(struct stack*,char);
char pop(struct stack*);
char peek(struct stack*);
int isEmpty(struct stack*);
int isOperand(char);
void infixtoPostfix(char[]);
int isp(char);
int icp(char);
int main()
{
    char infix[50];
    st.top = -1;
    printf("Enter Infix Expression");
    scanf("%s",infix);
    printf("\nInfix Expression is: %s",infix);
    infixtoPostfix(infix);
    return 0;
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
void infixtoPostfix(char infix[MAX])
{
    int i,j=0;
    char postfix[MAX];
    char sym,topsym;
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        if(isOperand(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(sym == '(')
        {
            push(&st,sym);
        }
        else if(sym == ')')
        {
            topsym = pop(&st);
            while(!isEmpty(&st) && topsym!='(')
            {
                postfix[j]=topsym;
                j++;
                topsym = pop(&st);
            }
        }
        else
        {
            while(!isEmpty(&st) && icp(sym)<=isp(peek(&st)))
            {
                topsym = pop(&st);
                postfix[j]=topsym;
                j++;                
            }
            push(&st,sym);
        }
    }
    while(!isEmpty(&st))
    {
        topsym = pop(&st);
        postfix[j]=topsym;
        j++; 
    }
    postfix[j]='\0';
    printf("\nPost fix Expression is:  %s",postfix);
}
void push(struct stack *stp,char sym)
{
    if(stp->top == MAX-1)
    {
        printf("Stack is over flow");
    }
    else
    {
        stp->top =stp->top+1;
        stp->items[stp->top]=sym;
    }
}
char pop(struct stack *stp)
{
    char sym;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        sym = stp->items[stp->top];
        stp->top=stp->top-1;
        return sym;
    }
}
char peek(struct stack *stp)
{
    char sym;
    if(stp->top==-1)
    {
        return -1;
    }
    else
    {
        sym = stp->items[stp->top];
        return sym;
    }
}
int isEmpty(struct stack *stp)
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
int isp(char c)
{
    switch (c)
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
int icp(char c)
{
    switch (c)
    {
        case '+': 
        case '-':return 1;
        case '*': 
        case '/':return 2;  
        case '$': 
        case '^':return 3;
    }
}