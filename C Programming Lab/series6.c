#include<stdio.h>
int main()
{
    int n,i,c=1,d=1;
    float x,s=0.0,f=1.0;
    printf("enter no of terms");
    scanf("%d",&n);
    printf("enter the value of x");
    scanf("%f",&x);
    for(i=1;i<=n;i++)
    {
        f=f*x;
        c=c*i;
        s=s+(f*d)/c;
        d=d*(-1);
    }
    printf("sum=%f",s);
    return 0;
}
