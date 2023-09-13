#include<stdio.h>
void printnum(int);
int main()
{
    int n;
    printf("Enter the size of array");
    scanf("%d",&n);
    printnum(n);
    return 0;
}
void printnum(int n)
{
    if(n==0)
    {
        //return 0;
        printf("%d\n",n);
;
    }
    else
    {
        printf("%d\n",n);
        return printnum(n-1);
    }
}