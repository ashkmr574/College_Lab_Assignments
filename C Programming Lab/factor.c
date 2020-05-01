#include<stdio.h>
int main()
{
    int n,i,s=0;
    printf("enter any no.");
    scanf("%d",&n);
    for(i=1;i<=n/2;i++)
    {
    if(n%i==0)
        s=s+i;
    }
    printf("sum of factors=%d\n",s);
    if(s==n)
        printf("perfect");
    else
    printf("not perfect");
    return 0;
}
