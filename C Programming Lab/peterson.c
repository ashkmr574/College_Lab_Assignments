#include<stdio.h>
int main()
{
 int n,f,num,s=0,r;
 printf("enter any number");
 scanf("%d",&n);
 num=n;
 while(n>0)
 {
     r=n%10;
     f=1;
     while(r>0)
           {
               f=f*r;
               r--;
           }
            s=s+f;
     n=n/10;
 }
 if(num==s)
    printf("peterson");
 else
    printf("not peterson");
 return 0;
}
