#include<stdio.h>
int l_search(int[],int,int);
int lr_search(int[],int,int);
int b_search(int[],int,int);
int br_search(int[],int,int,int);
int main()
{
    int n,a[10],k,i,index;
    printf("Enter the size of array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search");
    scanf("%d",&k);
    index=br_search(a,0,n-1,k);
    //res=linearsearch(a,n,k);
    if(index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d",index);
    }
    return 0;
}
int l_search(int a[10],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    if(i==n)
    {
        return -1;
    }
}
int lr_search(int a[10],int n,int k)
{
    if(n<0)
    {
        return -1;
    }
    if(a[n]==k)
    {
        return n;
    }
    else
    {
        return lr_search(a,n-1,k);
    }
}
int b_search(int a[10],int n,int k)
{
    int low,high,mid;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==k)
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
int br_search(int a[10],int low,int high,int k)
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
        return br_search(a,low,mid-1,k);
    }
    else{
        return br_search(a,mid+1,high,k);
    }

}
