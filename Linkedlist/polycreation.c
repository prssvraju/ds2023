#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp,cof;
    struct node *next;
};
struct node* inserPoly(struct node*,int,int);
struct node* getNode(int,int);
void display(struct node*);
struct node* getNode(int cof,int exp)
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->exp =exp;
    newnode->cof =cof;
    newnode->next =NULL;
    return newnode;
}

int main()
{
    struct node *p1head;
    int cof,exp,n,i;
    p1head = NULL;
    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial..");
    for(i=1;i<=n;i++)
    {
        printf("Enter %d term in Expression",i);
        scanf("%d%d",&cof,&exp);
        p1head = inserPoly(p1head,cof,exp);
    }
    display(p1head);
    return 0;
}
struct node* inserPoly(struct node* phead,int cof,int exp)
{
    struct node *newnode,*temp;
    newnode=getNode(cof,exp);
    if(phead==NULL || exp>phead->exp)
    {
        newnode->next=phead;
        phead = newnode;
        return phead;
    }
    else
    {
        temp=phead;
        while (temp->next!=NULL && exp<phead->exp)
        {
            temp=temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        return phead;
    }
}
void display(struct node *phead)
{
    struct node *temp;
    temp=phead;
    if(phead==NULL)
    {
        printf("\nEmpty..");  
    }
    else
    {
        while (temp!=NULL)
        {
            printf("%dX^%d",temp->cof,temp->exp);
            temp=temp->next;
            if(temp!=NULL)
            {
                printf("+");
            }
            else
            {
                printf("\n");
            }
        }
        
    }
}