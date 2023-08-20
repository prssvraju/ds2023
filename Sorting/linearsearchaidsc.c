#include<stdio.h>
int main()
{
    int n,i,k,flag=0;
    int a[10];
    printf("Enter n value");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter Key value");
    scanf("%d",&k);

    for(i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            flag=1;
        }
        
    }
    if(flag==1)
    {
        printf("Element  found\n");
    }
    else
    {
        printf("Element not found\n");

    }

    return 0;
}
