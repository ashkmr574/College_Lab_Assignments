#include<stdio.h>
int sum(int);
int main()
{
int n,s;
printf("enter n");
scanf("%d",&n);
s=sum(n);
printf("sum=%d",s);
}
int sum(int n)
{
if(n==0)
return 0;
else
return(n+sum(n-1));
}
