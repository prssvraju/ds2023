#include<stdio.h>
int fact(int);
int main()
{
    int n,res;
    printf("Enter n value");
    scanf("%d",&n);
    res=fact(n);
    printf("The fact is %d",res);
    return 0;
}
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}