#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
int pop();
void display();
int peek();
int stack[MAX],top=-1;
int main()
{
    int ch,ele;
    struct stack st;
    st.top=-1;
    
    while(1)
    {
        printf("\n**** Menu *****\n");
        printf("\n1.Push");
        printf("\n2.pop");
        printf("\n3.display");
        printf("\n4.peek");
        printf("\n5.Exit");
        printf("\nEnter your option\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                printf("\nEnter element to insert\n");
                scanf("%d",&ele);
                push(&st,ele);
                break;
        case 2:
                ele=pop();
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("Removed element is %d\n",ele);
                }
                break;
        case 3:
                display();
                break;
        case 4:
                ele=peek();
                if(ele==-1)
                {
                    printf("Stack is empty");
                }
                else
                {
                    printf("First element is %d\n",ele);
                }
                break;
        case 5:
                exit(0);
                break;
        default:
                printf("Invalid Choice");  
                break;
        }
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
int pop()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else
    {
        ele=stack[top];
        top=top-1;
        return ele;
    }
}
int peek()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else
    {
        ele=stack[top];
        return ele;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("Stack is empty");
    }
    else
    {
        for(i=top;i>=0;i--)
        {
            printf("|%d|\n",stack[i]);
        }
    }
}