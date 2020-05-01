#include<stdio.h>
int main()
{

int n,i,c;
printf("enter any no");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    c=i*i;
if(c==n)
{
printf("perfect square");
break;
}
}
if(c!=n)
    printf("not perfect square");
return 0;
}
