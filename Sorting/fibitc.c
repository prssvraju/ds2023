#include<stdio.h>
void fibs(int);
int main()
{
    int a[10],n,i,k,index,low,high;
    printf("Enter the size of array");
    scanf("%d",&n);
    fibs(n);
    return 0;
}
void fibs(int n)
{
    int fb1,fb2,fbn,i;
    fb1=0;
    fb2=1;
    printf("%d\t%d",fb1,fb2);
    for(i=0;i<n;i++)
    {
        fbn=fb1+fb2;
        printf("\t%d",fbn);
        fb1=fb2;
        fb2=fbn;
    }

}