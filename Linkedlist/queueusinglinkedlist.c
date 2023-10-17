#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front,*rear;
};
void insert(struct queue*,int);
int del(struct queue*);
int empty(struct queue*);
void display(struct queue*);
struct node* getNode();

struct node * getnode()
{
	struct node * newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=0;
	newnode->next=NULL;
	return newnode;
}
int main()
{
	int choice,x;
	struct queue q;
    q.front=NULL;
    q.rear=NULL;
	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.Enqueue(push)\n2.Dqueue(pop)\n3.empty\n4.display\n");
		printf("5.exit\n*******************\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&x);
			insert(&q,x);
			display(&q);
			break;
		case 2:x=del(&q);
			if(x==-1)
				printf("\nQueue is empty");
			else
				printf("deleted item is:%d",x);
			//display(&q);
			break;
		case 3:if(empty(&q))
				printf("\nQueue is empty");
			else
				printf("\nQueue is nonempty");
			break;
		case 4:display(&q);
			break;
		case 5:exit(0);
		}
	}
    return 0;
}
void insert(struct queue *qu,int a)
{
    struct node * newnode;
    newnode = getnode();
    newnode->data =a;

    if(qu->rear == NULL)
    {
        qu->front =qu->rear =newnode;
    }
    else
    {
        qu->rear->next = newnode;
        qu->rear = newnode;
    }
	
}
int del(struct queue *qu)
{
    int ele;
    if(qu->front == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        ele = qu->front->data;
        qu->front=qu->front->next;
        return ele;
    }
    
  
}
void display(struct queue *qu)
{
    struct node *temp = qu->front;
	if(temp == NULL)
    {
        printf("Queue is empty");
    }
    else
    {
        while(temp!=NULL)
        {
            printf("%d-->",temp->data);
            temp=temp->next;
        }

    }
}
int empty(struct queue *qu)
{
	if (qu->front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
