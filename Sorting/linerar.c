#include<stdio.h>
void  lin_s(int[],int,int);
int main()
{
    int a[10],n,i,k,index;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key element");
    scanf("%d",&k);
    lin_s(a,n,k);
    return 0;
}
void lin_s(int a[10],int n,int k)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            return i;
        }
    }
    if(i==n)
    {
        return -1;
    }
}