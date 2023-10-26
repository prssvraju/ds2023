#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node* getNode();
struct node* create();
void traversal(struct node*);
struct node *insert(struct node *);
struct node *delete(struct node *);
struct node * getNode()
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->data=0;
    np->next =NULL;
    return np;
}
struct node * create()
{
    struct node *head,*first,*newnode;
    first=getNode();
    head=first;
    newnode = getNode();
    printf("Enter the -99 to stop list");
    printf("Enter value");
    scanf("%d",&newnode->data);
    while (newnode->data!=-99)
    {
        first->next = newnode;
        first=newnode;
        newnode=getNode();
        printf("Enter value");
        scanf("%d",&newnode->data);
        newnode->next = head->next;

    }
    
    return head->next;
}

int main()
{
    int ch;
    struct node *start;
    start = create();
    traversal(start);
    while (1)
    {
        printf("\n**************\nMENU\n***********\n");
        printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            start = insert(start);
            traversal(start);
            break;
        case 2:
            traversal(start);
            break;
        case 3:
            start = delete (start);
            traversal(start);
            break;
        case 4:
            exit(0);

        default:printf("Invalid Choice");
        }
    }
}
struct node *insert(struct node *head)
{
    struct node *temp , *newnode;
    int ch,pos,i;
    temp = head;
    newnode = getNode();
    printf("enter value:");
    scanf("%d",&newnode->data);
    while(1)
    {
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    head=newnode;
                    return head;
                    break;
            case 2:
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    newnode->next=head;
                    temp->next = newnode;
                    return head;
                    break;
            case 3: 
                    printf("enter which position");
                    scanf("%d",&pos);
                    if(pos==1){
                        while(temp->next!=head)
                        {
                            temp=temp->next;
                        }
                        newnode->next=head;
                        temp->next = newnode;
                        head=newnode;
                        return head;
                    }
                    else {
                        for(i=1;i<pos-1;i++)
                        {
                            temp=temp->next;
                        }
                        newnode->next=temp->next;
                        temp->next=newnode;
                        return head;
                    }
            default:printf("Invalid Choice");
     }

    }
}
void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("list is empty");
    }
    else
    {
        while (temp->next!=head)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->",temp->data);
    }
    
}

struct node *delete(struct node *head){
    int ch,pos,i;
    struct node *temp,*secondtemp;
    temp = head;

    if (temp==NULL){
        printf("list is empty");
    }
    else{
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                if(temp->next==head)
                {
                    head=NULL;
                    return head;
                }
                else
                {
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    secondtemp=head->next;
                    temp->next = secondtemp;
                    head->next=NULL;
                    return secondtemp;
                }
                break;
            case 2:
                    if(temp->next==head)
                    {
                        head=NULL;
                        return head;
                    }
                    else
                    {
                        while(temp->next->next!=head)
                        {
                            temp=temp->next;
                        }
                        temp->next=head;
                        return head;
                    }
                break;
            case 3 :
                printf("enter which position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    if(temp->next==head)
                        {
                            head=NULL;
                            return head;
                        }
                        else
                        {
                            while(temp->next!=head)
                            {
                                temp=temp->next;
                            }
                            secondtemp=head->next;
                            temp->next = secondtemp;
                            head->next=NULL;
                            return secondtemp;
                        }
                }
                else{
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;

                    }
                    temp->next=temp->next->next;
                    return head;
                }
                break;
        }       
    }
}