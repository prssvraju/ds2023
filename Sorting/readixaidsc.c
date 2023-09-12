#include<stdio.h>
int largest(int[],int);
int noofdigits(int);
void radix(int[],int);
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
    radix(a,n);
    printf("\nElement after sorting\n");
    for(i=0;i<n;i++)
    {
        printf("\t%d",a[i]);
    }
    return 0;
}
int largest(int a[10],int n)
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
int noofdigits(int n)
{
    int dig=0;
    while(n>0)
    {
        dig=dig+1;
        n=n/10;
    }
    return dig;
}
void radix(int a[10],int n)
{
    int bucket[10][12],bc[10];
    int i,j,k;
    int rem,pass,nop,larg,div=1;
    larg=largest(a,n);
    nop=noofdigits(larg);
    printf("Larges is %d",larg);
    printf("No of digits is %d",nop);
 
    for(pass=0;pass<nop;pass++)
    {
        for(i=0;i<10;i++)
        {
            bc[i]=0;
        }
        for(i=0;i<n;i++)
        {
            rem=(a[i]/div)%10;
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
        div=div*10;
    }


}