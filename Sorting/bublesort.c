#include<stdio.h>
void bubbleSort(int[],int);
void selectionSort(int[],int);
void insertionSort(int[],int);
int main()
{
    int a[10],n,i;
    printf("Enter n value");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nElement before sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    insertionSort(a,n);
    printf("\nElement after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    return 0;
}
void bubbleSort(int a[10],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
    }
}
void selectionSort(int a[10],int n)
{
    int i,j,temp,min;
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
        if(i!=min)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
}
void insertionSort(int a[10],int n)
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



