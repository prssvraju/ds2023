#include<stdio.h>
#include<stdlib.h>
#define MAX 4
void push(int);
int pop();
int peek();
void display();
int stack[MAX];
int top=-1;
int main()
{
    int ele,ch;
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
                    push(ele);
                    break;
            case 2:
                    ele=pop();
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
                    display();
                    break;
            case 4:
                    ele=peek();
                    if(ele==-1)
                    {
                        printf("Empty");
                    }
                    else
                    {
                        printf("Top element is %d",ele);
                    }
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
void push(int ele)
{
    if(top==MAX-1)
    {
        printf("Over flow");
    }
    else
    {
        top=top+1;
        stack[top]=ele;
    }
}
int pop()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else{
        ele = stack[top];
        top=top-1;
        return ele;
    }
}
void display()
{
    int i;
    for(i=top;i>=0;i--)
    {
    printf("|%d|\n",stack[i]);
    }
}
int peek()
{
    int ele;
    if(top==-1)
    {
        return -1;
    }
    else{
        ele = stack[top];
        return ele;
    }
}
