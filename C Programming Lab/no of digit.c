#include<stdio.h>
int count(int);
int main()
{
int n,c;
printf("enter n");
scanf("%d",&n);
c=count(n);
printf("no of digit=%d",c);
}
int count(int n)
{
if(n==0)
return 0;
else
return(1+count(n/10));
}
