#include<stdio.h>
int main()
{
    int a[10],n,i=0;
    printf("enter the decimal no.");
    scanf("%d",&n);
    while(n>0)
    {
        a[i++]=n%2;
        n=n/10;
    }
    i--;
    while(i>=0)
    {
        printf("%d",a[i]);
        i--;
    }
    return 0;
}
