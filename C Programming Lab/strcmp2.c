#include<stdio.h>
#include<string.h>
int main()
{
int a[100],b[100],i;
printf("enter two strings");
gets(a);
gets(b);
i=strcmp(a,b);
printf("%d",strcmp(a,b));
return 0;
}
