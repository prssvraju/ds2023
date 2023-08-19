#include<stdio.h>
//void create_OneDArr(int[],int);
//void print_OneDArr(int[],int);

void create_TwoDArr(int,int,int[10][10]);
void print_TwoDArr(int,int,int[10][10]);

int main()
{
    int m,n,i;
    int a[10];
    //one dimentional Array
    //printf("Enter the size of array");
    //scanf("%d",&n);
    //create_OneDArr(a,n);
    //print_OneDArr(a,n);

    //Two Dimentional Array
    printf("Enter the size of Matrix M and N");
    scanf("%d%d",&m,&n);
    create_TwoDArr(m,n,a);
    print_TwoDArr(m,n,a);

    return 0;
   
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

void create_TwoDArr(int m,int n,int a[m][n])
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }    
    }
}
void print_TwoDArr(int m,int n,int a[m][n])
{
    int i,j;
    printf("---- The Matrix is ---");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d",a[i][j]);
        }
         printf("\n");    
    }
}