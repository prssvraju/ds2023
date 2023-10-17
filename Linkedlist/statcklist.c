#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct stack
{
    struct node *top;
};
struct node * getNode();
void push(struct stack*,int);
int pop(struct stack*);
int peek(struct stack*);
void display(struct stack*);
int empty(struct stack*);
void push (struct stack *st,int ele)
{
    struct node *newnode;
    newnode=getNode();
    newnode->data = ele;
    if(st->top == NULL)
    {
        st->top = newnode;
    }
    else
    {
        newnode->next=st->top;
        st->top =newnode;
    }
}
int peek(struct stack *st)
{
    int ele;
    if(st->top ==  NULL)
    {
        return -1;
    }
    else
    {
        ele = st->top->data;
        return ele;
    }
}
int pop(struct stack *st)
{
    int ele;
    if(st->top ==  NULL)
    {
        return -1;
    }
    else
    {
        ele = st->top->data;
        st->top = st->top->next;
        return ele;
    }
}
void display(struct stack *st)
{
    struct node *temp;
    temp = st->top;
    if(st->top == NULL)
    {
        printf("List is Empty");
    }
    while (temp!=NULL)
    {
       printf("|%d|",temp->data);
       temp=temp->next;
    }
}
struct node * getNode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next =NULL;
    return newnode;
}
int empty(struct stack *st)
{
    if(st->top==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{   struct stack st;
    st.top = NULL;
    int ch,ele,res;
    while(1)
	{
		printf("\n*************************\n\n\tMENU\n**********************\n");
		printf("1.push\n2.pop\n3.Display\n4.peek\n5.Empty\n");
		printf("6.exit\n*******************\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
            case 1: printf("\nenter the element:");
                scanf("%d",&ele);
                push(&st,ele);
                display(&st);
                break;
            case 2:	res=pop(&st);
                if(res==-1)
                    printf("\nstack is empty");
                else
                    printf("deleted item is:%d\n",res);
                display(&st);
                break;
            case 3:	display(&st);
                break;
            case 4: res=peek(&st);
                    if(res==-1)
                        printf("\nstack is empty");
                    else
                        printf("peek item is:%d\n",res);
                    display(&st);
                    break;
            case 5: res=empty(&st);
                    if(res == 1)
                    {
                        printf("\nstack is empty");
                    }
                    else
                    {
                        printf("\nstack is Not empty");
                    }

            case 6:	exit(0);
                break;
            default :
                    printf("Invalid choice");
		}
    }
    return 0;
}