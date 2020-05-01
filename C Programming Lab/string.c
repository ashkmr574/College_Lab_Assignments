#include<stdio.h>
int main()
{
char a[10][20];
int i;
printf("enter names");
for(i=0;i<10;i++)
gets(a[i]);
for(i=0;i<10;i++)
{
    printf("%s",a[i]);
    printf("\n");
}
return 0;
}
