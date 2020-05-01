#include<stdio.h>
int main()
{
    int a,b,i,p=1;
    printf("enter the value of a and b");
    scanf("%d%d",&a,&b);
    for(i=1;i<=b;i++)
    {
        p=p*a;
    }
    printf("%d",p);
    return 0;
}
