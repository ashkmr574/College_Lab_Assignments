#include<stdio.h>
int main()
{
 float n,i=1;
 printf("enter a no\n");
 scanf("%f",&n);
 while(i<=n)
  {
   if(n/i==i)
   {
    printf("perfect square\n");
    break;
   }
   i++;
  }
  if(i==n+1)
  printf("not a perfect square no");
  return 0;
  }


