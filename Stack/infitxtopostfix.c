#include<stdio.h>
#define MAX 10
struct stack
{
    char items[MAX];
    int top;
};
struct  stack st;
void push(struct stack*,char);
char pop(struct stack*);
char peek(struct stack*);
int isEmpty(struct stack*);
int isOperand(char);
void infixpost(char[]);
int icp(char);
int isp(char);
int main()
{
    int infix[MAX];
    st.top=-1;
    printf("Enter string ");
    scanf("%s",infix);
    infixpost(infix);
    return 0;
}
int isOperand(char sym)
{
    if((sym>='0' && sym<='9')||(sym>='A' && sym<='Z')||(sym>='a' && sym<='z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void infixpost(char infix[MAX])
{
    char postfix[MAX];
    int i,j=0;
    char sym,topsym;
    printf("\nInfix string is %s\n",infix);
    for(i=0;(sym=infix[i])!='\0';i++)
    {
        printf("\nSymbol is %c\n",sym);
        if(isOperand(sym))
        {
            postfix[j]=sym;
            j++;
        }
        else if(sym=='(')
        {
            push(&st,sym);
        }
        else if (sym==')')
        {
            topsym=pop(&st);
            while(!isEmpty(&st)&& topsym!='(')
            {
                postfix[j]=topsym;
                j++;
                topsym=pop(&st);
            }
        }
        else
        {
            while(!isEmpty(&st)&& icp(sym)<=isp(peek(&st)))
            {
                topsym=pop(&st);
                postfix[j]=topsym;
                j++;
            }
            push(&st,sym);
        }   
    }
    //  for(i=0;(sym=infix[i])!='\0';i++)
    // {
    //     if(isOperand(sym))
    //     {
    //         postfix[j]=sym;
    //         j++;
    //     }
    //     else if(sym == '(')
    //     {
    //         push(&st,sym);
    //     }
    //     else if(sym == ')')
    //     {
    //         topsym = pop(&st);
    //         while(!isEmpty(&st) && topsym!='(')
    //         {
    //             postfix[j]=topsym;
    //             j++;
    //             topsym = pop(&st);
    //         }
    //     }
    //     else
    //     {
    //         while(!isEmpty(&st) && icp(sym)<=isp(peek(&st)))
    //         {
    //             topsym = pop(&st);
    //             postfix[j]=topsym;
    //             j++;                
    //         }
    //         push(&st,sym);
    //     }
    // }
    while(!isEmpty(&st))
    {
        topsym=pop(&st);
        postfix[j]=topsym;
        j++;
    }
    postfix[j]='\0';
    printf("Post fix expression is %s",postfix);
}
void push(struct stack *st,char sym)
{
    if(st->top==MAX-1)
    {
        printf("Overflow");
    }
    else
    {
        st->top =st->top+1;
        st->items[st->top]=sym;
    }
}
char pop(struct stack *st)
{
    char ch;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        ch=st->items[st->top];
        st->top=st->top-1;
        return ch;
    }
    
}

char peek(struct stack *st)
{
    char ch;
    if(st->top == -1)
    {
        return -1;
    }
    else
    {
        ch=st->items[st->top];
        return ch;
    }
}
int isEmpty(struct stack *st)
{
    if(st->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isp(char sym)
{
    switch (sym)
    {
        case '(':   return 0;
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
        case '^':
        case '$':   return 3;
    }
}
int icp(char sym)
{
    switch (sym)
    {
        case '+':
        case '-':   return 1;
        case '*':
        case '/':   return 2;
        case '^':
        case '$':   return 3;
    }
}
