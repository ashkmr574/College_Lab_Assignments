#include<stdio.h>
int fact(int,int);
int main()
{
int n,f=1,g;
printf("enter n");
scanf("%d",&n);
g=fact(n,f);
printf("fctorial=%d",g);
}
int fact(int n,int f)
{
if(n==0)
return f;
else
return fact(n-1,n*f);
}
