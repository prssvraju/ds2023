#include<stdio.h>
void bubble_s(int[],int);
void selection_s(int[],int);
void insertion_s(int[],int);
void quick_s(int[],int,int);
int partation(int[],int,int);
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
    a[i]=99;
    quick_s(a,0,n);
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