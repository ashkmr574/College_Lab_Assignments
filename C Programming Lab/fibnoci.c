#include<stdio.h>
unsigned long long int fib(unsigned long long int);
int main()
{
unsigned long long int n,i,f;
printf("enter n");
scanf("%llu",&n);
for(i=1;i<=n;i++)
{
f=fib(i);
}
printf("%llu",f);
}
unsigned long long int fib(unsigned long long int n)
{
if(n==1)
return 1;
else if(n==2)
return 2;
else
return(fib(n-1)+fib(n-2));
}
