#include<stdio.h>
void quickSort(int[],int,int);
int partition(int[],int,int);
int main()
{
    int n,i;
    int arr[10];
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    arr[i]=99;
    quickSort(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    } 
}
void quickSort(int a[10],int low,int high)
{
    int j;
    if(low<high)
    {
        j=partition(a,low,high+1);
        quickSort(a,low,j-1);
        quickSort(a,j+1,high);
    }
}

int partition(int a[10],int low,int high)
{
    int i,j,pivot,temp;
    pivot = a[low];
    i=low;
    j=high;
    while(i<j)
    {
        while(a[i]<=pivot && i<high)
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

