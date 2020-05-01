#include<stdio.h>
void fromdigit(int a,int b)
{
	int sum=0,k=0,c[100],n,i;
   while(a>0)
   {
   	c[k]=a%b;
   	a=a/b;
   	k++;
   }
   n=k-1;
   for(i=n;i>=0;i--)
   printf("%d",c[i]);
}
int main()
{
    int n,b,t;
        printf("enter num \n");
        scanf("%d",&n);
        fromdigit(n,2);
    return 0;
}
