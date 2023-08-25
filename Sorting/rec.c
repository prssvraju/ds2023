#include<stdio.h>
int fact(int);
int main()
{   
    int n,res;
    printf("enter the size of array");
    scanf("%d",&n);
    res = fact(n);
    printf("Fact of %d is %d",n,res);
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