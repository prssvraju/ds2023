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
    int i,large;
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
int noofdigits(int n)
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
    int bucket[10][12],bc[10],divisor=1;
    int i,j,k;
    int large,pass,nop,rem;
    large=largest(a,n);
    nop=noofdigits(large);
    printf("\nLargest Number is %d\n",large);
    printf("\n Number of digits is %d\n",nop);
    for(pass=0;pass<nop;pass++){

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
        for(j=0;j<10;j++)
        {
            for(k=0;k<bc[j];k++)
            {
                a[i]=bucket[j][k];
                i++;
            }
        }
        divisor =divisor*10;
    }


}