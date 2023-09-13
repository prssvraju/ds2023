#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct queue
{
    int items[MAX];
    int front,rear;
};
void insert(struct queue*,int);
int delete(struct queue*);
void display(struct queue*);
int isempty(struct queue*);
int main()
{
    int ch,ele;
    struct queue qu;
    qu.front=0;
    qu.rear=-1;
    while(1)
    {
        printf("\n**** Menu *****\n");
        printf("\n1.Insert");
        printf("\n2.delete");
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
                insert(&qu,ele);
                break;
        case 2:
                ele=delete(&qu);
                if(ele==-1)
                {
                    printf("Queue is empty");
                }
                else
                {
                    printf("Removed element is %d\n",ele);
                }
                break;
        case 3:
                display(&qu);
                break;
        case 4:
                //ele=peek();
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
void insert(struct queue *qup, int ele)
{
    if(qup->rear== MAX-1)
    {
        printf("Queue is full");
    }
    else
    {
        qup->rear=qup->rear+1;
        qup->items[qup->rear]=ele;
    }
}
int delete(struct queue *qup)
{
    int ele;
    if(qup->rear<qup->front)
    {
        return -1;
    }
    else{
        ele=qup->items[qup->front];
        qup->front=qup->front+1;
        return ele;
    }
}
void display(struct queue *qup)
{
    int i;
    if(qup->rear<qup->front)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i=qup->front;i<=qup->rear;i++)
        {
            printf("\n%d indexed element is |%d|",i,qup->items[i]);
        }
    }
    
}