#include<stdio.h>
void radixSort(int[],int);
int largestNum(int[],int);
int noPass(int);
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
    radixSort(arr,n);
    printf("\nElements after Sorting\n"); 
    for(i=0;i<n;i++)
    { 
        printf("%d \t",arr[i]);
    } 
}
int largestNum(int a[10],int n)
{
    int large,i;
    large=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large=a[i];
        }
    }
    return large;
}
int noPass(int n)
{
    int pass=0;
    while(n>0)
    {
        pass=pass+1;
        n=n/10;
    }
    return pass;
}
void radixSort(int a[10],int n)
{
    int bucket[10][12],bc[10],i,j,k,divisor=1;
    int rem,pass,largnum,nop;
    largnum=largestNum(a,n);
    nop=noPass(largnum);
    printf("\nLargest is %d\n",largnum);
    printf("\nNo of digits is %d\n",nop);
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            rem=(a[i]/divisor)%10;
            bucket[rem][bc[rem]]=a[i];
            bc[rem]=bc[rem]+1;
        }
        i=0;
        for(k=0;k<10;k++)
        {
            for(j=0;j<bc[k];j++)
            {
                a[i]=bucket[k][j];
                i++;
            }
        }
        divisor=divisor*10;
    }
}