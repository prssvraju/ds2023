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

int main()
{
    int ele,ch;
    struct stack s;
    s.top=-1;
    while(1)
    {
        printf("==============\n");
        printf("------MENU----\n");
        printf("==============\n");
        printf("1.Push\n");
        printf("2.pop\n");
        printf("3.display\n");
        printf("4.peek\n");
        printf("5.exit\n");
        printf("Please enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Enter value to push\n");
                    scanf("%d",&ele);
                    push(&s,ele);
                    break;
            case 2:
                    ele=pop(&s);
                    if(ele==-1)
                    {
                        printf("Empty");
                    }
                    else
                    {
                        printf("Removed element is %d",ele);
                    }
                    break;
            case 3:
                    display(&s);
                    break;
            case 4:
                    printf("Peek");
                    break;
            case 5:
                    exit(0);
                    printf("Exit");
                    break;
            default:
                    printf("Invalid choice");
                    break;

        }
    }
}
void push(struct stack *sp,int ele)
{
    if(sp->top==MAX-1)
    {
        printf("Over flow");
    }
    else
    {
        sp->top=sp->top+1;
        sp->items[sp->top]=ele;
    }
}
int pop(struct stack *sp)
{
    int ele;
    if(sp->top==-1)
    {
        return -1;
    }
    else{
        ele = sp->items[sp->top];
        sp->top=sp->top-1;
        return ele;
    }
}
void display(struct stack *sp)
{
    int i;
    for(i=sp->top;i>=0;i--)
    {
    printf("|%d|\n",sp->items[i]);
    }
}
