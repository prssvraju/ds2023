#include<stdio.h>
int main()
{
	int a[10],x,i,n,j,temp,low,high,mid;
	printf("enter the size of array:");
	scanf("%d",&x);
	printf("the array elements are:");
	for(i=0;i<x;i++)
	scanf("%d",&a[i]);
	for(i=0;i<x;i++)
	{
		for(j=i+1;j<x;j++)
		{
			if(a[i]>a[j])
			{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		}
	}
	printf("the sorted elements are:");
	for(i=0;i<x;i++)
	printf("%d\t",a[i]);
	printf("\nenter the element to be found:");
	scanf("%d",&n);
	low=0;
	high=x-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==n)
		{
			printf("element %d is found at %d",n,mid);
			break;	
		}
        if(a[mid]<n)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
	}
	if(low>high)
	{
		printf("element is not found");
	}
}

