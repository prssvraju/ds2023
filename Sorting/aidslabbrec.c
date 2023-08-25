#include<stdio.h>
int b_search_rec(int[],int,int,int);
int main()
{
    int a[10],n,i,k,index,low,high;
    printf("enter the size of array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search");
    scanf("%d",&k);
    low=0;
    high=n-1;
    index=b_search_rec(a,low,high,k);

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
int b_search_rec(int a[10],int low,int high,int k)
{
    int mid;
    mid=(low+high)/2;
    if(low>high)
    {
        return -1;

    }
    if(a[mid]==k)
    {
        return mid;
    }
    else if(a[mid]>k)
    {
       return b_search_rec(a,low,mid-1,k);
    }
    else
    {
        return b_search_rec(a,mid+1,high,k);
    }

}