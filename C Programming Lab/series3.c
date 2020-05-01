#include<stdio.h>
int main()
{
    int n,i,s=0,f=2;
    printf("enter no of terms");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        s=s+f;
        f=f*2;
    }
    printf("sum=%d",s);
    return 0;
}
