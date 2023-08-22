#include<stdio.h>
int getfibnumber(int);
int fibsearch(int[],int,int);

int main()
{
    int a[10],n,i,k,index;
    printf("Enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key element");
    scanf("%d",&k);
    index = fibsearch(a,n,k);
    if(index == -1)
    {
        printf("Enter element is not found");
    }
    else
    {
        printf("Element is found at %d",index);
    }
    return 0;


 }
 int fibsearch(int a[10],int n,int k)
 {
    int low,high,loc,flag,index;
    low=0;
    high=n-1;
    loc=-1;
    flag=0;
    while(flag!=1 && low<=high)
    {
        index=getfibnumber(n);
        if(a[index+low]==k)
        {
            flag=1;
            loc=index+low;
            break;
        }
        else if(a[index+low]>k)
        {
            high=index+low-1;
        }
        else
        {
            low=index+low+1;
        }
        n=high-low+1;
    }
    if(flag == 1)
    {
        return loc;
    }
    else
    {
        return -1;
    }
 }
 int getfibnumber(int n)
 {
    int fb1,fb2,fb3;
    fb1=0;
    fb2=1;
    fb3=0;
    if(n==1||n==0)
    {
        return 0;
    }
    else
    {
        while(fb3<n)
        {
            fb3=fb1+fb2;
            fb1=fb2;
            fb2=fb3;
        }
        return fb1;
    }
 }