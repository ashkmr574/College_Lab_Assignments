#include<stdio.h>
int main()
{
 int n,f,a,i,s=0,num=n;
 printf("enter a no\n");
 scanf("%d",&n);
 while(n>0)
  {
   a=n%10;
   n=n/10;
   f=1;
   i=1;
   while(i<=a)
    {
     f=f*i;
     i++;
    }
   s=s+f;
   }
   printf("sum=%d",s);
   return 0;
}
