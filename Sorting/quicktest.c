#include<stdio.h>
void quick_s(int[],int,int);
int partation(int[],int,int);
int main()
{
    int n,i;
    int arr[20];
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[i]=99;
    quick_s(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=1;i<=n;i++)
    { 
        printf("%d \t",arr[i]);
    } 
}
void quick_s(int a[10],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partation(a,low,high+1);
        quick_s(a,low,j-1);
        quick_s(a,j+1,high);
    }
}
int partation(int a[10],int low,int high)
{
    int i,j,pivot,temp;
    i=low;
    j=high;
    pivot=a[low];
    while(i<j)
    {
        while(a[i]<=pivot && i<=high)
        {
            i++;
        }
        while(a[j]>pivot && j>low)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}