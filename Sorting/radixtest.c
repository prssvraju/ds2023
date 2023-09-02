#include<stdio.h>
int largestNo(int[],int);
int noOfDigits(int);
void radix(int[],int);
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
    radix(a,n);
    printf("\n---Elements After sorting---\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    return 0;
}
int largestNo(int a[10],int n)
{   
    int large,i;
    large=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]>large)
        {
            large = a[i];
        }
    }
    return large;
}
int noOfDigits(int n)
{
    int nodigits=0;
    while(n>0)
    {
        nodigits=nodigits+1;
        n=n/10;
    }
    return nodigits;
}
void radix(int a[10],int n)
{
    int bucket[10][12],bc[10],divisor=1,i,j,k,rem;
    int large,pass,nop;
    large=largestNo(a,n);
    nop=noOfDigits(large);
    printf("\nLargest no %d\n",large);
    printf("\nNo of Digits %d\n",nop);
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
        divisor =divisor*10;
    }
}