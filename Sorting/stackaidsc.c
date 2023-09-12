#include<stdio.h>
#include<stdlib.h>
#define MAX 3
struct stack
{
    int items[MAX];
    int top;
};

void push(struct stack*,int);
int pop(struct stack*);
int peeek(struct stack*);
void display(struct stack*);
int isempty(struct stack*);
int main()
{
    int ch,ele;
    struct stack st;
    st.top=-1;
    while(1)
    {
        printf("\n-----------\n");
        printf("\n---MENU----\n");
        printf("\n-----------\n");
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.peek");
        printf("\n5.Is empty");
        printf("\n6.Exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:printf("Enter element to insert");
                    scanf("%d",&ele);
                    push(&st,ele);
                    break;
            case 2: ele=pop(&st);
                    if(ele==-1)
                    {
                        printf("Under flow");
                    }
                    else
                    {
                         printf("Element removed is %d",ele);
                    }
                    break;
            case 3:display(&st);
                    break;
            case 4:ele=pop(&st);
                    if(ele==-1)
                    {
                        printf("Under flow");
                    }
                    else
                    {
                         printf("Top Element  is %d",ele);
                    }
                    break;
            case 5:
                    if(isempty(&st))
                    {
                        printf("Stack is empty");
                    }
                    else
                    {
                            printf("Not empty");
                    }
                    break;
            case 6:exit(0);
                    break;
            default : printf("invalid choice");                                                                
        }
    }

    return 0;
}
void push(struct stack *stp,int ele)
{
    if(stp->top==MAX-1)
    {
        printf("Over flow");
    }
    else
    {
        stp->top=stp->top+1;
        stp->items[stp->top]=ele;
    }
}
int pop(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        return -1;

    }
    else
    {
        ele= stp->items[stp->top];
        stp->top=stp->top-1;
        return ele;
    }
}
int peek(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        return -1;

    }
    else
    {
        ele= stp->items[stp->top];
        return ele;
    }
}
void display(struct stack *stp)
{
    int i;
    for(i=stp->top;i>=0;i--)
    {
        printf("|%d|\n",stp->items[i]);
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