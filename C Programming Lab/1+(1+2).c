#include<stdio.h>
int main()
{
 int n,i=1,j,s=0;
 printf("enter the no of term");
 scanf("%d",&n);
 while(n>=i)
  {
   s=s+i;
   for(j=1;j<i;j++)
   s=s+j;
   i++;
  }
  printf("sum=%d",s);
  return 0;
}
