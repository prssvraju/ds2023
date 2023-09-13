#include<stdio.h>
void b_sort(int[],int);
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
    b_sort(a,n);
    printf("\nElement After  sorting\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void b_sort(int a[10],int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}