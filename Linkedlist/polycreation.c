#include<stdio.h>
#include<stdlib.h>
struct node
{
    int exp,cof;
    struct node *next;
};
struct node* inserPoly(struct node*,int,int);
struct node* addPoly(struct node*,struct node*);
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
    //Creation of ploy
    // struct node *p1head;
    // int cof,exp,n,i;
    // p1head = NULL;
    // printf("Enter the no of terms of polynomial 1..");
    // scanf("%d",&n);
    // printf("\nEnter the polynomial..");
    // for(i=1;i<=n;i++)
    // {
    //     printf("Enter %d term in Expression",i);
    //     scanf("%d%d",&cof,&exp);
    //     p1head = inserPoly(p1head,cof,exp);
    // }
    // display(p1head);
    
    //Addition
    struct node *p1head,*p2head,*p3head;
    p1head=p2head=p3head=NULL;
    int i,n1,n2,cof,exp;

    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n1);
    printf("\nEnter the polynomial..");
    for(i=1;i<=n1;i++)
    {
        printf("\nEnter %d term in Expression",i);
        scanf("%d%d",&cof,&exp);
        p1head = inserPoly(p1head,cof,exp);
    }
    printf("Enter the no of terms of polynomial 2..");
    scanf("%d",&n2);
    printf("\nEnter the polynomial..");
    for(i=1;i<=n2;i++)
    {
        printf("\nEnter %d term in Expression",i);
        scanf("%d%d",&cof,&exp);
        p2head = inserPoly(p2head,cof,exp);
    }


    display(p1head);
    display(p2head);
    p3head=addPoly(p1head,p2head);
    printf("\nAddition of two polynomial Expression is \n");
    display(p3head);
    return 0;
}
struct node * addPoly(struct node *p1head,struct node *p2head)
{
    struct node *p3head;
    p3head = NULL;
    while (p1head!=NULL && p2head!=NULL)
    {
            if(p1head->exp == p2head->exp)
            {
                p3head = inserPoly(p3head,p1head->cof+p2head->cof,p1head->exp);
                p1head=p1head->next;
                p2head=p2head->next;
            }
            else if(p1head->exp>p2head->exp)
            {
                p3head = inserPoly(p3head,p1head->cof,p1head->exp);
                p1head=p1head->next;
            }
            else
            {
                p3head = inserPoly(p3head,p2head->cof,p2head->exp);
                p2head=p2head->next;
            }
    }
    while(p1head!=NULL)
    {
        p3head = inserPoly(p3head,p1head->cof,p1head->exp);
        p1head=p1head->next;
    }
    while (p2head!=NULL)
    {
        p3head = inserPoly(p3head,p2head->cof,p2head->exp);
        p2head=p2head->next;
    }
    return p3head;
    

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