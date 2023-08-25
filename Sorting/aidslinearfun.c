#include<stdio.h>
int l_search(int[],int,int);
int main()
{
    int a[10],n,i,k,index;
    printf("enter the size of array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search");
    scanf("%d",&k);
    index=l_search(a,n,k);
    if(index==-1)
    {
        printf("Not found");
    }
    else
    {
        printf("Element is found at %d",index);
    }
    return 0;
}
int l_search(int a[10],int n,int k)
{
    if(n<0)
    {
        return -1;
    }    
    else if(a[n] == k)
    {
        return n;
    }
    else
    {
        return l_search(a,n-1,k);
    }
    
}