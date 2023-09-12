#include<stdio.h>
int largest(int[],int);
int noofdigits(int);
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
    //a[i]=99;
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
int largest(int a[10],int n)
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
int noofdigits(int n)
{
    int digits=0;
    while(n>0)
    {
        digits=digits+1;
        n=n/10;
    }
    return digits;
}
void radix(int a[10],int n)
{
    int bucket[10][12],bc[10],rem,div=1;
    int pass,nop,large,i,k,j;
    large=largest(a,n);
    nop=noofdigits(large);
    printf("\n largest No is %d\n",large);
    printf("\n No of digits is %d\n",nop);
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

