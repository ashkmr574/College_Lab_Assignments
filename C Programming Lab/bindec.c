#include<stdio.h>
int main()
{

    int rem,num,s=0,i=0;
    printf("enter a binary no");
    scanf("%d",&num);
    while(num>0)
    {
        rem=num%10;
        num=num/10;
        s=s+(rem*pow(2,i));
        i++;
    }
    printf("decimal no=%d ",s);
    return 0;
}
