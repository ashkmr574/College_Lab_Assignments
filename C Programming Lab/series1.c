#include<stdio.h>
int main()
{
    int n,i,s=0;
    printf("enter no of terms");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        s=s+(i*i);
    printf("sum=%d",s);
    return 0;
}
