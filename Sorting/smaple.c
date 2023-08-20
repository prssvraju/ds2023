#include<stdio.h>
int* readArr(int);
int main()
{
  int *a, n,i;
  printf("Enter the size of arrray");
  scanf("%d",&n);
  a=readArr(n);
  for(i=0;i<n;i++)
  {
    printf("%d",a[i]);
  }
  return 0;
}
int* readArr(int n)
{
    int a[10];
    int *res =a;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    return res;
    
}