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
k=i-1;
while(l<k)
{
t=a[l];
a[l]=a[k];
a[k]=t;
l++;
k--;
}
    l=i+1;
}
    if(a[i]!=' '&&a[i+1]=='\0')
    {k=i;
    while(l<k)
    {
t=a[l];
a[l]=a[k];
a[k]=t;
l++;
k--;
    }}}
    puts(a);
return 0;
}
