#include<stdio.h>
int f_search(int[],int,int,int);
int fibnum(int);
int main()
{
    int a[10],n,i,k,index;
    printf("enter the size of array");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter key to search");
    scanf("%d",&k);
    index=f_search(a,0,n-1,k);

    if(index==-1)
    {
        printf("Not found");
    }
    else
    {
        printf("Element is found at %d",index);
    }
    return 0;
}
int f_search(int a[10],int low,int high,int k)
{
    int flag=0,loc=-1,n,index=0;
   

    while(low<=high&&flag!=1)
    {
        index=fibnum(n);
        if (k == a[index + low]) 
		{
			flag = 1; 
			loc = index + low;
			break;
		}
		else if (a[index + low]>k)
        {
            high =index+low-1;
        }
		else 
		{
            low= index+low+1;
		}
        n=high-low+1;
    }
    if(flag==1)
    {
        return loc;
    }
    else
    {
        return -1;
    }

}

int fibnum(int n)
{
    int fib1=0,fib2=1,fib3=0;
    if(n==0||n==1)
    {
        return 0;
    }
    while(fib3<n)
    { 
               fib3 = fib2 + fib1;
               fib1 = fib2;
               fib2 = fib3;
    }
    return fib1;
}