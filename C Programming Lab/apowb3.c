#include<stdio.h>
int apowb(int,int);
int main()
{
int a,b,p;
printf("enter a and b");
scanf("%d%d",&a,&b);
p=apowb(a,b);
printf("%d",p);
}
int apowb(int a,int b)
{
if(b==0)
return 1;
else
return(a*apowb(a,b-1));
}
