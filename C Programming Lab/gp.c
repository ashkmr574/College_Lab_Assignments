#include<stdio.h>
int main()
{
 int n,a=2,i=1,r=1,s=0;
 printf("enter the no of term");
 scanf("%d",&n);
 while(n>=i)
  {
  s=s+a*r;
  r=r*2;
  i++;
  }
  printf("sum=%d",s);
  return 0;
  }
