#include<stdio.h>
void mergeSort(int[],int,int);
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

    printf("---Elements before sorting---\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    mergeSort(a,0,n);
    printf("\n---Elements After sorting---\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
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
    int i,j,k,b[10];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(a[i]<=a[j])
        {
            b[k]=a[i];
            k++;i++;
        }
        else
        {
            b[k]=a[j];
            k++;j++;
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
        k++;j++;
    }
    for(i=low;i<=high;i++)
    {
        a[i]=b[i];
    }

}