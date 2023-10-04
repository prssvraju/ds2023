#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node * getNode();
struct node * create();
struct node* insert(struct node *);
struct node* delete(struct node *);

void traversal(struct node*);
int main()
{
    struct node* first;
    int ch;
	first=create();
	traversal(first);
    while (1)
    {
        printf("\n**************\nMENU\n***********\n");
        printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insert(first);
            traversal(first);
            break;
        case 2:
            traversal(first);
            break;
        case 3: 
                first=delete(first);
                traversal(first);
                break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
// struct node * delete(struct node *head)
// {
//     struct node *temp;
//     int i,pos,ch;

//     temp=head;
    
//     if(head == NULL)
//     {
//         printf("List is empty");
//     }
//     else
//     {
//         printf("\n Enter your choice\n 1.Delete At Begning \n2.Delete At End \n3.Delete At position");
//         scanf("%d",&ch);
//         switch (ch)
//         {
//         case 1:
//                 head = head->next;
//                 temp->next = NULL;
//                 return head;
//                 break;
//         case 2:
//                 while(temp->next->next!=NULL)
//                 {
//                     temp=temp->next ;
//                 }
//                 temp->next = NULL;
//                 return head;
//                 break;
//         case 3:
//                 printf("Enter positio to remove");
//                 scanf("%d",&pos);
//                 if(pos==1)
//                 {
//                     head = head->next;
//                     temp->next = NULL;
//                     return head;
//                 }
//                 else
//                 {
//                     for(i=0;i<pos-1;i++)
//                     {
//                         temp=temp->next;
//                     }
//                     temp->next = temp->next->next;
//                     return head;
//                 }
//                 break;
//             default:
//                 break;
//         }
//     }
// }

struct node *delete (struct node *head)
{
    struct node *temp;
    int i, ch, pos;
    temp = head;
    if (head == NULL)
    {
        printf("\nlist is empty");
        return head;
    }
    else
    {
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = head->next;
            temp->next = NULL;
            return head;
            break;
        case 2:

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            return head;
        case 3:
            printf("\nEnter the position to Delete:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                head = head->next;
                temp->next = NULL;
                return head;
            }
            else
            {
                for (i = 1; i < pos - 1; i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                return head;
            }

        default:

            break;
        }
    }
}
struct node * insert(struct node *head)
{
    struct node *temp,*newnode;
    int pos,i,ch;
    temp=head;
    newnode=getNode();
    printf("Enter the element");
    scanf("%d",&newnode->data);
    printf("\n Enter your choice\n 1.insert At Begning \n2.insert At End \n3.insert At position");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
               newnode->next = head;
               head = newnode;
               return head;
               break;
        case 2:
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=newnode;
                return head;
                break;
        case 3: 
                printf("Enter the positiont to inert");
                scanf("%d",&pos);
               
                if(pos == 1)
                {
                    newnode->next=head;
                    head=newnode;
                    return head;
                }
                else
                {
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;
                    }
                    newnode->next = temp->next;
                    temp->next=newnode;
                    return head;
                }
                break;
        default :
                 break;

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