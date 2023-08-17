#include<stdio.h>
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
{
    int i;
    for(i=0;i<n;i++)
    {
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