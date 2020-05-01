#include<stdio.h>
int main()
{
 int j,r,m,n,i=0,s=0;
 printf("enter a no\n");
 scanf("%d",&n);
 while(n>0)
  {
   if(n%10<=1)
    {
     r=n%10;
     m=1;
     for(j=0;j<i;j++)
     m=m*2;
     s=s+r*m;
     n=n/10;
     i++;
     }
     else
     {
      printf("not a binary\n");
      break;
      }
    }
    printf("dec=%d",s);
    return 0;
    }
