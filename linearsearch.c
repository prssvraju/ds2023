#include<stdio.h>
int linearsearch(int[],int,int);
int linearsearchwithrec(int[],int,int);
int main()
{
    int n,a[10],k,i,res;
    printf("Enter the size of array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search");
    scanf("%d",&k);

    //res=linearsearch(a,n,k);
    res=linearsearchwithrec(a,n,k);
    if(res == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d",res);
    }
    return 0;
}
int linearsearchwithrec(int a[10],int n,int k)
{
    if(n<0)
    {
        return -1;
    }
    else if(a[n]==k)
    {
        return n;
    }
    else
    {
        return linearsearchwithrec(a,n-1,k);
    }
}
int linearsearch(int a[10],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
            break;
        }
    }
    if(i==n)
    {
        return -1;
    }
}