#include<stdio.h>
int main()
{
    int n,num,s=0;
    printf("enter the no");
    scanf("%d",&n);
    num=n;
    while(n>0)
    {
    s=s+((n%10)*(n%10)*(n%10));
    n=n/10;
}
if(s==num)
    printf("armstrong");
else
    printf("not armstrong");
return 0;
}
