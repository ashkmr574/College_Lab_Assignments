#include<stdio.h>
int main()
{
struct student
{
char name[20];
int roll;
int marks;
};
struct student s[3];
int i;
for(i=0;i<=2;i++)
{
fflush(stdin);
gets(s[i].name);
scanf("%d%d\n",&s[i].roll,&s[i].marks);
}
for(i=0;i<=2;i++)
    printf("\n%c%d%d",s[i].name,s[i].roll,s[i].marks);
return 0;
}

