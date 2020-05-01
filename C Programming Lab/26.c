#include<stdio.h>
int main()
{
	int a[10],i,j,temp;
	printf("enter array");
	for(i=0;i<10;i++)
	scanf("%d",&a[i]);
	for(i=0;i<10;i++)
	{
		for(j=0;j<10-i;j++)
		{
			if(a[j+1]>a[j])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<10;i++)
	printf("%d\t",a[i]);
	for(i=9;i>=0;i--)
	{
		if(a[i-1]>a[i])
		{
			printf("second smallest no=%d",a[i-1]);
			break;
		}
	}
}
