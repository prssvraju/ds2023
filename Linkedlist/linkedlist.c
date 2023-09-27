#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * getNode();
struct node * create();
struct node * insert(struct node*);
struct node * delete(struct node *);
struct node * delete (struct node *head)
{
    struct node *temp;
    temp=head;
    int i,pos,ch;
    printf("\nEnter your choice");
    printf("\n1.Dlete At Begning \n2.Delete At End\n 3.Delete At Possion");
    scanf("%d",&ch);
    switch (ch)
    {
        case 1:
                head=head->next;
                temp->next = NULL;
                return head;
                break;
        case 2: 
                while(temp->next->next !=NULL)
                {
                    temp=temp->next;
                }
                temp->next = NULL;
                return head;
                break;
        case 3:
                printf("Enter the position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    head=head->next;
                    temp->next = NULL;
                    return head;
                }
                else
                {
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;
                    }
                    temp->next=temp->next->next;
                    return head;
                }
                break;
        default:
                break;
    }
}

struct node *insert(struct node *head)
{
    struct node *temp,*newnode;
    int ch,i,pos;
    temp=head;
    newnode = getNode();
    printf("Enter element ");
    scanf("%d",&newnode->data);
    printf("\nEnter your choice");
    printf("\n1.Insert At Begning \n2.Insert At End\n 3.Insert At Possion");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
            newnode->next = head;
            head=newnode;
            return head;
            break;
    case 2:
            while (temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            return head;
    case 3:
            printf("Enter the position");
            scanf("%d",&pos);
            if(pos==1)
            {
                newnode->next = head;
                head=newnode;
                return head;
            }
            else
            {
                for(i=1;i<pos-1;i++)
                {
                    temp=temp->next;
                }
                newnode->next=temp->next;
                temp->next=newnode;
                return head;
            }
    default:
        break;
    }
}

void traversal(struct node*);
int main()
{
    struct node* first;
    int ch;
	first=create();
	traversal(first);
    while(1)
    {
        printf("Enter your Choice\n");
        printf("1.Insert\n2.Delete\n3.traversal\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    first=insert(first);
                    traversal(first);
                    break;
            case 2:
                    first = delete(first);
                    traversal(first);
                    break;
            case 3:
                    traversal(first);
                    break;
            case 4:
                    exit(0);
                    break;
            default:
                    break;

        }
    }
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