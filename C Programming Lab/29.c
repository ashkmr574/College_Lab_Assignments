#include<stdio.h>
int main()
{
	int a[20],i,j,b[1000]={0},c[20],p=0;
	for(i=0;i<20;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]++;
	}
	printf("frequency of each no is\n");
	for(i=0;i<1000;i++)
	{
		if(b[i]!=0)
	printf("%d\t%d\n",i,b[i]);
    }
	return 0;
}
