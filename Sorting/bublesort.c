#include<stdio.h>
void bubbleSort(int[],int);
int main()
{
    int a[10],n,i;
    printf("Enter n value");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubbleSort(a,n);
    printf("Element before sorting");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

}