#include<stdio.h>
void bubble_s(int[],int);
void selection_s(int[],int);
void insertion_s(int[],int);
void quick_s(int[],int,int);
int partation(int[],int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
//raghu
int main()
{
    int n,a[10],i;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nElement Before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    //a[i]=99;
    mergesort(a,0,n);
    printf("\nElement After  sorting\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void bubble_s(int a[10],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void selection_s(int a[10],int n)
{
    int i,j,min,temp;
    for(i=0;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
}
void insertion_s(int a[10],int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0;j--)
        {
            if(a[j]>temp)
            {
                a[j+1]=a[j];
            }
            else
            {
                break;
            }
        }
        a[j+1]=temp;
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
void mergesort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void merge(int a[10],int low,int mid,int high)
{
    int b[10],i,j,k;
    k=low;
    i=low;
    j=mid+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++;i++;
        }
        else
        {
            b[k]=a[j];
            j++;k++;
        }
    }
    while(i<=mid)
    {
         b[k]=a[i];
         k++;i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        j++;k++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}