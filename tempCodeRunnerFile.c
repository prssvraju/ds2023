#include<stdio.h>
#define MAX 4
int stack[MAX];
int top=-1;
int main()
{
    int ele,ch;
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
                printf("push");
                break;
        case 2:
                printf("pop");
                break;
        case 3:
                printf("display");
                break;
        case 4:
                printf("peek");
                break;
        case 5:
                printf("Exit");
                break;
        default:
                printf("Invalid choice");
                break;

    }

    

}