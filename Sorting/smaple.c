#include<stdio.h>
int* readArr(int);
void printArr(int[],int);
int main()
{
  int n,i;
  int *a;
  printf("Enter n value ");
  scanf("%d",&n);
  a=readArr(n);
  printArr(a,n);
  return 0;
}
void printArr(int a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(a+i));
    }
}

int* readArr(int n)
{
    int i;
    int al[10];
    for(i=0;i<n;i++)
    {
        scanf("%d",al[i]);
    }
    return al;
}

