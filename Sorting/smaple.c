#include<stdio.h>
<<<<<<< HEAD
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
=======
void create_OneDArr(int[],int);
void print_OneDArr(int[],int);

main()
{
    int n,i;
    int a[10];
    printf("Enter the size of array");
    scanf("%d",&n);
    create_OneDArr(a,n);
    print_OneDArr(a,n);
   

}

void create_OneDArr(int a[10],int n)
>>>>>>> acf94bc56a7cdda014eb5de7d00fb48c9cc0fac1
{
    int i;
    for(i=0;i<n;i++)
    {
<<<<<<< HEAD
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

=======
        scanf("%d",&a[i]);
    }
}
void print_OneDArr(int a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }

}
>>>>>>> acf94bc56a7cdda014eb5de7d00fb48c9cc0fac1
