#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack*);
int peek(struct stack*);
int main()
{
    int ch,ele,n,a[10],i;
    struct stack st;
    st.top=-1;
    printf("Enter the size of array");
    scanf("%d",&n);
    printf("Enter Array elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        push(&st,a[i]);
    }
    for(i=0;i<n;i++)
    {
        a[i]=pop(&st);
    }
    printf("Elements after reversing ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

    

    return 0;
}
void push(struct stack *stp,int ele)
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
int pop(struct stack *st)
{
    int ele;
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
int peek(struct stack *st)
{
    int ele;
    if(st->top==-1)
    {
        return -1;
    }
    else
    {
        ele=st->items[st->top];
        return ele;
    }
}
void display(struct stack *st)
{
    int i;
    if(st->top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=st->top;i>=0;i--)
        {
            printf("|%d|\n",st->items[i]);
        }
    }
}