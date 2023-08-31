#include<stdio.h>
void meargSort(int[],int,int);
void mearg(int[],int,int,int);
int main()
{
    int n,i;
    int arr[10];
    printf("Enter array length");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    meargSort(arr,0,n);
    printf("Elements after Sorting"); 
    for(i=0;i<=n;i++)
    {
        printf("%d \t",arr[i]);
    } 
    return 0;
}
void meargSort(int a[10],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        meargSort(a,low,mid);
        meargSort(a,mid+1,high);
        mearg(a,low,mid,high);
    }
}
void mearg(int a[10],int low,int mid, int high)
{
    int b[10],i,j,k=low;
    i=low;
    j=mid+1;
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
  
        while(j<=high)
        {
            b[k]=a[j];
            k++;
            j++;
        }

  

        while(i<=mid)
        {
            b[k]=a[i];
            k++;
            i++;
        }
 
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}