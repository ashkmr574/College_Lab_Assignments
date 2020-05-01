#include<stdio.h>
int prime(int);
int main()
{
int n,rev=0,f,g;
    printf("enter any number  ");
    scanf("%d",&n);
    f=prime(n);
    while(n>0)
    {
     rev=rev*10+n%10;
     n=n/10;
    }
    printf("reverse of number is =%d\n",rev);
    g=prime(rev);
    if(f==g)
        printf("twisted prime");
    else
        printf("not twisted prime");
    return 0;
}
int prime(int n)
{
  int flag=0,i;
        for(i=2;i<=n/2;i++)
        {
        if(n%i==0)
        {
        flag=1;
        break;
        }
}
        if(flag==0)
            {
                printf("prime\n");
            return 0;
            }
        else
        {
            printf("not prime\n");
            return 1;
        }

}
