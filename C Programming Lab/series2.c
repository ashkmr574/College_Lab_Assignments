#include<stdio.h>
int main()
{
    int n,i,s=0,f=0;
    printf("enter no of terms");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        f=f+i;
        s=s+f;
    }
    printf("sum=%d",s);
    return 0;
}
