#include<stdio.h>
void quickSort(int[],int,int);
int partition(int[],int,int);
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
    int i,n, a[10];
    printf("Enter size of arr");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //a[i]=99;
    printf("---Elements before sorting---\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    mergesort(a,0,n);
    printf("\n---Elements After sorting---\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
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
    i=low;
    j=high;
    pivot=a[low];
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
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;
            i++;
        }
        else
        {
            b[k]=a[j];
            k++;
            j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++;
        j++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }


}
