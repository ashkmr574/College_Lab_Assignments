#include<stdio.h>
int binsearch(int a[],int left,int right,int num);
int main()
{
	int a[100],n,i,j,temp,num,ser;
	printf("enter size of array\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(a[j+1]>a[j])
			{
				temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=n;i>0;i--)
	printf("%d\t",a[i]);
	printf("enter no. to be search\n");
	scanf("%d",&num);

	ser=binsearch(a,0,n-1,num);
	if(ser==-1)
	printf("no is not found\n");
	else
	printf("no is found at pos %d",ser+1);
	return 0;
}
int binsearch(int a[],int l,int r,int num)
{
	int mid;
	while(l<=r)
	{
	mid=(l+r)/2;
	if(a[mid]==num)
	{
       return mid;
    }
	else if(num<a[mid])
	return binsearch(a,0,mid-1,num);
	else
	return binsearch(a,mid+1,r,num);
   }
	return -1;
}
