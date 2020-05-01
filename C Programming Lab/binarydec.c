#include<stdio.h>
int main()
{
int n,i,j,n1,s,r,t,m;
n1=i=j=r=s=t=0;
m=1;
printf("enter any no");
scanf("%d",&n);
n1=n;
while(n!=0)
{
++i;
if((n%10==1)||(n%10==0))
t=t+1;
n=n/10;
}
if(t<i)
printf("not in binary");
else
{
n=n1;
i=0;
while(n!=0)
{
r=n%10;
m=1;
for(j=0;j<i;j++)
m*=2;
s=s+r*m;
n=n/10;
i++;
}
printf("decimal no=%d",s);
}
return 0;
}
