#include<stdio.h>
int b_search(int[],int,int,int);
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
    index=b_search(a,0,n-1,k);

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
int b_search(int a[10],int low,int high,int k)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]== k)
        {
            return mid;
        }
        else if(a[mid]>k)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(low>high)
    {
        return -1;
    }
}