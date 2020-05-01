#include<stdio.h>
main()
{
    int a,b,n,s;
    printf("enter terms");
    scanf("%d",&n);
    a=0;
    b=1;
    printf("%d\n",a);
    printf("%d\n",b);
    n=n-2;
    while(n>0)
    {
        s=a+b;
        printf("%d\n",s);
        a=b;
        b=s;
        n--;
    }
}
