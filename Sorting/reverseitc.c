#include<stdio.h>
#define MAX 4
struct stack
{
    int items[MAX];
    int top;
};
void push(struct stack*,int);
int pop(struct stack*);
int main()
{   
    struct stack st;
    int n,i,a[10];
    st.top=-1;
    printf("Enter n value");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nElement before Reversing\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    for(i=0;i<n;i++)
    {
        push(&st,a[i]);
    }
    for(i=0;i<n;i++)
    {
        a[i]=pop(&st);
    }
    printf("\nElement After Reversing\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }

    return 0;

}
void push(struct stack *stp,int ele)
{
    if(stp->top == MAX-1)
    {
        printf("Overflow");
    }
    else{
        stp->top=stp->top+1;
        stp->items[stp->top]=ele;
    }
}
int pop(struct stack *stp)
{
    int ele;
    if(stp->top==-1)
    {
        return -1;        
    }
    else{
        ele = stp->items[stp->top];
        stp->top=stp->top-1;
        return ele;
    }
}