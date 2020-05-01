#include<stdio.h>
#include<ctype.h>
int main()
{
char a[100],t;
int i,k,l=0;
printf("enter a sentence ");
gets(a);
for(i=0;a[i]!='\0';i++)
{
    if(a[i]==' '&&a[i+1]!=' ')
{
printf("%c. ",a[l]);
    l=i+1;
}
    if(a[i]!=' '&&a[i+1]=='\0')
        for(k=l;k<=i;k++)
    {
        printf("%c",a[k]);
    }}
return 0;
}
