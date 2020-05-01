#include<stdio.h>
#include<string.h>
int main()
{
char a[100],b[100],c[200];
int i,j,l,k,t;
printf("enter two strings\n");
gets(a);
gets(b);
for(i=0;a[i]!='\0';i++)
c[i]=a[i];
for(j=0;b[j]!='\0';j++)
c[i++]=b[j];
c[i]='\0';
strrev(c);
puts(c);
return 0;
}
