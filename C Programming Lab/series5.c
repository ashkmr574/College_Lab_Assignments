#include<stdio.h>
int main()
{
    int n,i,s=0;
    printf("enter no of terms");
    scanf("%d",&n);
    printf("1");
    for(i=2;i<=n;i++)
    {
        s=s+i;
        printf("+%d",i);
    }
    printf(" = %d",s+1);
    return 0;
}
