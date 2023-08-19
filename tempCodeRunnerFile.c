#include<stdio.h>
int main()
{
    int a[10],n,k,low,high,mid,i;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key element");
    scanf("%d",&k);
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==k)
        {
            printf("element is found at %d",mid);
        }
        else if(a[mid]>k)
        {
            high=mid-1;
        }
        else
        {
            low= mid+1;
        }
    }
}