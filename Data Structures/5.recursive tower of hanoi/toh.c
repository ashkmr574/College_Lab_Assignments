#include<stdio.h>
int toh(int n,char s,char a,char d)
{
    if(n>1)
        toh(n-1,s,d,a);
    printf("%dth disk is moved from %c to %c\n",n,s,d);
    if(n>1)
        toh(n-1,a,s,d);
}
int main()
{
    int n;
    printf("enter the no of disks\n");
    scanf("%d",&n);
    toh(n,'s','a','d');
    return 0;

}
