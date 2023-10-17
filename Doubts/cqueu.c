#include<stdio.h>
#include<stdlib.h>
#define MAX 4
struct cqueue
{
	int items[MAX];
	int rear,front;
};
void insert(struct cqueue*,int);
void display(struct cqueue*);
int del(struct cqueue*);
int main()
{
	int ch,ele;
    struct cqueue cq;
    cq.front=-1;
    cq.rear=-1;
    while(1)
    {
        printf("\n** Menu **\n");
        printf("\n1.insert");
        printf("\n2.delete");
        printf("\n3.display");
        printf("\n4.Exit");
        printf("\nEnter your option\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
                printf("\nEnter element to insert\n");
                scanf("%d",&ele);
                insert(&cq,ele);
                break;
        case 2:
                ele=del(&cq);
                if(ele==-1)
                {
                    printf("cqueue is empty");
                }
                else
                {
                    printf("Removed element is %d\n",ele);
                }
                break;
        case 3:
                display(&cq);
                break;
        
        case 4:
                exit(0);
                break;
        default:
                printf("Invalid Choice");  
                break;
        }
    }
}
void insert(struct cqueue*cq,int ele)
{
	if(((cq->front==0)&&(cq->rear==MAX-1))||(cq->front==cq->rear+1))
	{
		printf("cqueue is full");
		return;
	}
	if(cq->front==-1)
	{
		cq->front=0;
		cq->rear=0;
	}
	else
	{
		if(cq->rear==MAX-1)
		{
			cq->rear=0;
		}
		else
		{
			cq->rear++;
		}
	}
	cq->items[cq->rear]=ele;	
}
void display(struct cqueue*cq)
{
	int i;
	if(cq->front==-1)
	{
		printf("cqueue is empty");
	}
	else
	{
		if(cq->front <=cq->rear)
		{
			for(i=cq->front;i<=cq->rear;i++)
			{
				printf(" |%d|",cq->items[i]);
			}
		}
		else
		{
			for(i=cq->front;i<=MAX-1;i++)
			{
				printf(" |%d|",cq->items[i]);
			}
			for(i=0;i<=cq->rear;i++)
			{
				printf(" |%d|",cq->items[i]);
			}
		}
	}
}
int del( struct cqueue*cq)
{
	int ele;
	if(cq->front==-1)
	{
		return -1;
	}
	ele=cq->items[cq->front];
	if(cq->front==cq->rear)
	{
		cq->front=-1;
		cq->rear=-1;
	}
	else
	{
		if(cq->front=MAX-1)
		{
			cq->front=0;
		}
		else
		{
			cq->front++;
		}
	}
	return ele;
}