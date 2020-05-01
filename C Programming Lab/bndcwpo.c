#include<stdio.h>
int main()
{
    int n,r,j,i=0,s=0,m;
    printf("enter binary no");
    scanf("%d",&n);
    while(n>0)
    {
        r=n%10;
        m=1;
        for(j=0;j<i;j++)
            m=m*2;
        s=s+r*m;
        n=n/10;
        i++;
        }
        printf("decimal no=%d",s);
        return 0;
}
