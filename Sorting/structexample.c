#include<stdio.h>
# define TC 20;
struct student
{
    int roll;
    char name[10];
    int s1C;
    int s2C;
    int s3C;
    int s4C;
};
int getSGP(struct student*);
int main()
{
    struct student s;
    struct student *sp;
    sp=&s;
    printf("Enter the name of student");
    scanf("%s",s.name);

    printf("Enter the Roll of student");
    scanf("%d",&s.roll);
    
    printf("Enter the S1 credits");
    scanf("%d",&s.s1C);

    printf("Enter the S2 credits");
    scanf("%d",&s.s2C);

    printf("Enter the S3 credits");
    scanf("%d",&s.s3C);

    printf("Enter the S4 credits");
    scanf("%d",&s.s4C);    

    printf("The SGP is %d",getSGP(sp));
    return 0;
}
int getSGP(struct student *s)
{
    int sgp;
    sgp = (s->s1C+s->s2C+s->s3C+s->s4C)/TC;
    return sgp;
}