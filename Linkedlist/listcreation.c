#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * getNode();
struct node * create();
void traversal(struct node*);
int main()
{
    struct node* first;
	first=create();
	traversal(first);
}

void traversal(struct node* head)
{
    struct node *temp;
    temp=head;
    printf("Element are\n");
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }


}

struct node * getNode()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data=0;
    newnode->next = NULL;
    return newnode;
}
struct node * create()
{
   struct node *first,*head,*newnode;
   first=getNode();
   head=first;
   newnode=getNode();
   printf("Enter the element");
   scanf("%d",&newnode->data);
   while (newnode->data!=-9)
   {
        first->next=newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter the element");
        scanf("%d",&newnode->data);
   }
   return head->next;
   
}