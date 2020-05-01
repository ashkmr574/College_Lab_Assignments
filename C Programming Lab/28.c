#include<stdio.h>
int binsearch(int a[],int left,int right,int num);
int main()
{
	int a[100],n,i,j,temp,num,low,high,mid;
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
	low=0;
	high=n-1;
	printf("enter no. to be search\n");
	scanf("%d",&num);
	while(low<=high)
    {
        mid=(low+high)/i;
        if(a[mid]==n)
        {
            f=1;
            break;
        }
        else if(a[mid]>n)
            high=mid-1;
        else
            low=mid+1;
    }
    if(f==1)
        printf("found");
    else
        printf("not found");
    return 0;
}


