#include<stdio.h>
int main()
{
int a,b,c,m,n,lcm,gcd;
printf("enter a and b");
scanf("%d%d",&a,&b);
m=a;
n=b;
if(a>b)
{
    while(a%b!=0)
    {
        c=a%b;
        a=b;
        b=c;
    }
 gcd=b;
 printf("gcd=%d\n",gcd);
}
else
{
    while(b%a!=0)
    {
        c=b%a;
        b=a;
        a=c;
    }
    gcd=a;
    printf("gcd=%d\n",gcd);
}
lcm=(m*n)/gcd;
printf("lcm=%d",lcm);
return 0;
}
