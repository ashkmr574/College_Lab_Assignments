#include<stdio.h>
int main()
{

    int n,rem,flag=0;
    printf("enter any no.");
    scanf("%d",&n);
    while(n>2)
    {
        rem=n%2;
        if(rem==1)
        {
            flag=1;
        break;
        }
        else
            n=n/2;
    }
    if(flag==1)
        printf("not a power of 2");
    else
        printf("power of 2");
    return 0;
}
