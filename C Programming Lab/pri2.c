#include<stdio.h>
int main()
{
 int n,i=2;
 printf("enter a no\n");
 scanf("%d",&n);
 while(i<=n/2)
  {
   if(n%i==0)
    {
     printf("not a prime no");
     break;
     }
     i++;
    }
    if(i==n/2+1)
    printf("a prime no");
    return 0;
}
