#include<stdio.h>
int fibSe(int);
int f_search(int[],int,int);
int main()
{
    int n,a[10],k,i,index;
    printf("Enter the size of array");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search");
    scanf("%d",&k);
    index=f_search(a,n,k);
    //res=linearsearch(a,n,k);
    if(index == -1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element is found at %d",index);
    }
    return 0;
}
int f_search(int a[],int n,int k)
{
    int low,high,loc,flag,index;
    low=0;
    high=n-1;
    loc=-1;
    flag=0;
    while(low<=high && flag!=1)
    {
        index=fibSe(n);
        if(a[index+low] == k)
        {
            loc=index+low;
            flag = 1;
        }
        else if(a[index+low]>k)
        {
            high= index+low-1;
        }
        else{
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



int fibSe(int n)
{
    int fb1,fb2,fbn;
    fb1=0;
    fb2=1;
    if(n==0||n==1)
    {
        return 0;
    }
    while(fbn<n)
    {
        fbn=fb1+fb2;
        fb1=fb2;
        fb2=fbn;
    }
    return fb1;
}