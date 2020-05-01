#include<stdio.h>

int main()
{
int n,p=1;
float i,s=0;
printf("enter n");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
s=s+(p*i)/(i+1);
p=p*(-1);

}
printf("sum=%f",s);
}
