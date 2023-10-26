#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node* getNode();
struct node* create();
void traversal(struct node*);
struct node *insert(struct node *);
//struct node *delete(struct node *);
int main()
{
    int ch;
    struct node *head;
    head = create();
    traversal(head);
    while (1)
    {
        printf("\n**************\nMENU\n***********\n");
        printf("\n1.insert\n2.display\n3.Delete\n4.Exit\n");
        printf("\nenter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            head = insert(head);
            traversal(head);
            break;
        case 2:
            traversal(head);
            break;
        case 3:
            //head = delete (head);
            traversal(head);
            break;
        case 4:
            exit(0);

        }
    }
}
struct node * getNode()
{
    struct node *np;
    np = (struct node*)malloc(sizeof(struct node));
    np->data=0;
    np->next =NULL;
    np->prev = NULL;
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
        newnode->prev = first;
        first=newnode;
        newnode=getNode();
        printf("Enter value");
        scanf("%d",&newnode->data);
    }  
    return head->next;
}

void traversal(struct node *head)
{
    struct node *temp;
    temp=head;
    while (temp!=NULL)
    {
        printf("%d<->",temp->data);
        temp=temp->next;
    }
}

struct node *insert(struct node *head){
    struct node *temp , *newnode;
    int ch,pos,i;
    temp = head;
    newnode = getNode();
    printf("enter value:");
    scanf("%d",&newnode->data);
    printf("\n1.at begining\n2. at end\n3. at given position");
    printf("\nenter your choice:");
    scanf("%d", &ch);

    switch (ch){
        case 1:
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                return head;
                break;
        case 2:
                while(temp->next!=NULL){
                    temp = temp->next;
                    
                }
                temp->next= newnode;
                newnode->prev=temp;
                return head;
                break;
        case 3: 
                printf("enter which position");
                scanf("%d",&pos);
                printf("Temp/Head 1 Data is ");

                if(pos==1){
                newnode->next = head;
                head->prev = newnode;
                head = newnode;
                return head;
                }
                else {
                    printf("Temp/Head 2 Data is %d",temp->data);
                   for (i=1;i<pos-1;i++){
                       temp = temp->next;
                   }
                   printf("Temp Data is %d",temp->data);
                   newnode->next=temp->next;
                   newnode->prev=temp;
                   temp->next->prev=newnode;
                   temp->next=newnode;
                   
                }
                break;
        default:
                printf("Invalid Choice");
                break;
    }  
}

struct node *delete(struct node *head){
    int ch,pos,i;
    struct node *temp;
    temp = head;

    if (head==NULL){
        printf("list is empty");
    }
    else{
        printf("\n1.at begining\n2. at end\n3. at given position");
        printf("\nenter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                head =head->next;
                temp->next= NULL;
                return head;
                break;
            case 2:
                while(temp->next->next!=NULL)
                {
                    temp=temp->next;


                }
                temp->next=NULL;
                return head;
                break;
            case 3 :
                printf("enter which position");
                scanf("%d",&pos);
                if(pos==1)
                {
                    head =head->next;
                    temp->next= NULL;
                    return head;

                }
                else{
                    for(i=1;i<pos-1;i++)
                    {
                        temp=temp->next;

                    }
                    temp->next=temp->next->next;
                }
        }       

    }
}