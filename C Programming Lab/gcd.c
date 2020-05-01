#include<stdio.h>
int gcd(int,int);
int main()
{
int a,b,g;
printf("enter a and b\n");
scanf("%d%d",&a,&b);
if(a>b)
g=gcd(a,b);
else
g=gcd(b,a);
printf("gcd=%d",g);
}
int gcd(int a,int b)
{
if(a%b==0)
return b;
else
return gcd(b,a%b);
}



