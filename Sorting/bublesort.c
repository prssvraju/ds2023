#include<stdio.h>
void bubbleSort(int[],int);
void selectionSort(int[],int);
void insertionSort(int[],int);
int partition(int[],int,int);
void quickSort(int[],int,int);
void mergeSort(int[],int,int);
void merge(int[],int,int,int);
int largeNo(int[],int);
int noOfDigits(int);
void radixSort(int[],int);

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
    //a[i]=99;
    mergeSort(a,0,n);
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
        // Alternative way - I
        // j=i-1;
        // while(j>=0 && a[j]>temp)
        // {
        //     a[j+1]=a[j];
        //     j--;
        // }
        // Alternative way - II
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
        while(a[i]>=pivot && i<high)
        {
            i++;
        }
        while(a[j]<=pivot && j>low)
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
void mergeSort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
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
int largeNo(int a[10],int n)
{
    int large,i;
    large=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
        }
    }
    return large;
}

int noOfDigits(int n)
{
    int digits=0;
    while(n>0)
    {
        digits=digits+1;
        n=n/10;
    }
    return digits;
}
void radixSort(int a[10],int n)
{
    int buckets[10][12],bc[10],large,pass,nop,i,j,k;
    int rem,divisor=1;
    large=largeNo(a,n);
    nop=noOfDigits(large);
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            rem=(a[i]/divisor)%10;
            buckets[rem][bc[rem]]=a[i];
            bc[rem]=bc[rem]+1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bc[k];k++)
            {
                a[i]=buckets[k][j];
                i++;
            }
        }
        divisor = divisor*10;
    }
}