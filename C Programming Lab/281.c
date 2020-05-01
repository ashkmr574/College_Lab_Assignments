#include<stdio.h>
int main()
{
	int a[100],n,i,j,temp,num,low,high,mid;
	printf("enter size of array\n");
	scanf("%d",&n);
	printf("enter array elements one by one\n");
	for(i=0;i<n;i++)
	{
	    scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;(j<n-i-1);j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("sorted array is\n");
	for(i=0;i<n;i++)
    {
	printf("%d\n",a[i]);
    }
	printf("enter no. to be search\n");
	scanf("%d",&num);
	low=1;
	high=n;
	do
    {
        mid=(low+high)/2;
        if(num<a[mid])
            high=mid-1;
        else if(num>a[mid])
            low=mid+1;
    }while(num!=a[mid]&&low<=high);
    if(num==a[mid])
        {
            printf("found");
        }
    else
    {
        printf("not found");
    }
    return 0;
}


