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
struct node* getNode();
void enque(struct queue*,int);
int deque(struct queue*);
void display(struct queue*);
int isempty(struct queue*);
int main()
{
	int ch;
    int ele;
    struct queue q;
    q.front = NULL;
    q.rear=NULL;

	while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.Enqueue(push)\n2.Dqueue(pop)\n3.display\n4.Empty\n5.Exit\n");
		printf("*******************\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1: printf("\nenter the element:");
			scanf("%d",&ele);
			enque(&q,ele);
			display(&q);
			break;
		case 2:ele=deque(&q);
			if(ele==-1)
				printf("\nQueue is empty\n");
			else
				printf("deleted item is:%d\n",ele);
			display(&q);
			break;
		case 3:display(&q);
			break;
        case 4: if(isempty(&q))
                    printf("\nQueue is empty");
                else
                    printf("\nQueue is nonempty");
                break;
		case 5:exit(0);
		}
	}
    return 0;
}
int isempty(struct queue *qp)
{
    if(qp->rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void display(struct queue *qp)
{
    struct node *temp;
    temp=qp->front;
    if(qp->front==NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Lit of element are \n");
        while(temp!=NULL)
        {
            printf("|%d|",temp->data);
            temp=temp->next;
        }
    }


}
int deque(struct queue *qp)
{
    int ele;
    if(qp->front == NULL)
    {
        //printf("List is empty");
        ele =-1;
    }
    else
    {
        ele=qp->front->data;
        qp->front=qp->front->next;
    }
    return ele;
}

struct node* getNode()
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = 0;
    newnode->next = NULL;
    return newnode;
}
void enque(struct queue *qp,int ele)
{
    struct node *newnode;
    newnode=getNode();
    newnode->data=ele;
    if(qp->rear == NULL)
    {
        qp->rear=qp->front=newnode;
    }
    else
    {
        qp->rear->next=newnode;
        qp->rear=newnode;
    }
}