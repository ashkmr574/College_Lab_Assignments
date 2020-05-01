#include<stdio.h>
int main()
{
int n,r,m=1,s=0;
printf("enter a no\n");
scanf("%d",&n);
while(n>0)
  {
    if(n%10<=1)
    {
    r=n%10;
    s=s+r*m;
    m=m*2;
    n=n/10;
    }
    else
    {
    printf("not a binary no");
    break;
    }
  }
   if(s>0)
   printf("\ndecimal=%d",s);
   return 0;
}
