#include<stdio.h>
void swap(int a[]);
int main()
{
	int a[20],i;
	for(i=0;i<20;i++)
	scanf("%d\t",&a[i]);
	swap(a);
	for(i=0;i<20;i++)
	printf("%d\t ",a[i]);
	return 0;
}
void swap(int a[])
{
	int i,min,max,temp,pos1,pos2;
	min=999999;
	max=0;
	for(i=0;i<20;i++)
	{
		if(a[i]<=min)
		{
		pos1=i;
		min=a[i];
	    }
		if(a[i]>max)
		{
		pos2=i;
		max=a[i];
	    }
    }
    temp=a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=temp;
}
